#include <QtWidgets>

class CustomPrintDialog : public QPrintDialog {
    Q_OBJECT
public:
    CustomPrintDialog(QPrinter *printer, QWidget *parent = nullptr)
        : QPrintDialog(printer, parent) {
        // Create radio buttons for page range selection
        oddPagesRadioButton = new QRadioButton("Odd Pages", this);
        evenPagesRadioButton = new QRadioButton("Even Pages", this);
        allPagesRadioButton = new QRadioButton("All Pages", this);

        // Create layout for radio buttons
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(oddPagesRadioButton);
        layout->addWidget(evenPagesRadioButton);
        layout->addWidget(allPagesRadioButton);

        // Add radio buttons to the dialog
        QWidget *widget = new QWidget(this);
        widget->setLayout(layout);
        setOptionTabs({widget});

        // Connect signals and slots
        connect(oddPagesRadioButton, &QRadioButton::clicked, this, &CustomPrintDialog::setOddPages);
        connect(evenPagesRadioButton, &QRadioButton::clicked, this, &CustomPrintDialog::setEvenPages);
        connect(allPagesRadioButton, &QRadioButton::clicked, this, &CustomPrintDialog::setAllPages);
    }

public slots:
    void setOddPages() {
        printer()->setPageOrder(QPrinter::OddPages);
    }

    void setEvenPages() {
        printer()->setPageOrder(QPrinter::EvenPages);
    }

    void setAllPages() {
        printer()->setPageOrder(QPrinter::FirstPageFirst);
    }

private:
    QRadioButton *oddPagesRadioButton;
    QRadioButton *evenPagesRadioButton;
    QRadioButton *allPagesRadioButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a QTextDocument with the content you want to print
    QTextDocument document;
    document.setPlainText("This is a test document.");

    // Create a printer
    QPrinter printer;

    // Create a custom print dialog
    CustomPrintDialog printDialog(&printer);
    if (printDialog.exec() == QDialog::Accepted) {
        // Print the document
        document.print(&printer);
    }

    return app.exec();
}