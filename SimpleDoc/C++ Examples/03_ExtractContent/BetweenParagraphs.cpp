#include "pch.h"
using namespace Spire::Doc;

int main() {
	wstring input_path = DATAPATH;
	wstring inputFile = input_path + L"Sample.docx";
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path + L"BetweenParagraphs.docx";

	//Create the first document
	Document* sourceDocument = new Document();

	//Load the source document from disk.
	sourceDocument->LoadFromFile(inputFile.c_str());

	//Create a destination document
	Document* destinationDoc = new Document();

	//Add a section
	Section* section = destinationDoc->AddSection();

	//Extract content between the first paragraph to the third paragraph
	ExtractBetweenParagraphs(sourceDocument, destinationDoc, 1, 3);

	//Save the document.
	destinationDoc->SaveToFile(outputFile.c_str(), FileFormat::Docx);
	sourceDocument->Close();
	destinationDoc->Close();
	delete sourceDocument;
	delete destinationDoc;
}

void ExtractBetweenParagraphs(Document* sourceDocument, Document* destinationDocument, int startPara, int endPara)
{
	//Extract the content
	for (int i = startPara - 1; i < endPara; i++)
	{
		//Clone the ChildObjects of source document
		DocumentObject* doobj = sourceDocument->GetSections()->GetItem(0)->GetBody()->GetChildObjects()->GetItem(i)->Clone();

		//Add to destination document 
		destinationDocument->GetSections()->GetItem(0)->GetBody()->GetChildObjects()->Add(doobj);
	}
}
