#include "pch.h"
using namespace Spire::Doc;

int main() {
	wstring input_path = DATAPATH;
	wstring inputFile = input_path + L"MultiplePages.docx";
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path + L"OddAndEvenHeaderFooter.docx";
	//Load the document
	Document* doc = new Document();
	doc->LoadFromFile(inputFile.c_str());

	//Get the section and
	Section* section = doc->GetSections()->GetItem(0);

	//Set the DifferentOddAndEvenPagesHeaderFooter property to ture
	section->GetPageSetup()->SetDifferentOddAndEvenPagesHeaderFooter(true);

	//Add odd header
	Paragraph* P3 = section->GetHeadersFooters()->GetOddHeader()->AddParagraph();
	TextRange* OH = P3->AppendText(L"Odd Header");
	P3->GetFormat()->SetHorizontalAlignment(HorizontalAlignment::Center);
	OH->GetCharacterFormat()->SetFontName(L"Arial");
	OH->GetCharacterFormat()->SetFontSize(10);

	//Add even header
	Paragraph* P4 = section->GetHeadersFooters()->GetEvenHeader()->AddParagraph();
	TextRange* EH = P4->AppendText(L"Even Header from E-iceblue Using Spire.Doc");
	P4->GetFormat()->SetHorizontalAlignment(HorizontalAlignment::Center);
	EH->GetCharacterFormat()->SetFontName(L"Arial");
	EH->GetCharacterFormat()->SetFontSize(10);

	//Add odd footer
	Paragraph* P2 = section->GetHeadersFooters()->GetOddFooter()->AddParagraph();
	TextRange* OF = P2->AppendText(L"Odd Footer");
	P2->GetFormat()->SetHorizontalAlignment(HorizontalAlignment::Center);
	OF->GetCharacterFormat()->SetFontName(L"Arial");
	OF->GetCharacterFormat()->SetFontSize(10);

	//Add even footer
	Paragraph* P1 = section->GetHeadersFooters()->GetEvenFooter()->AddParagraph();
	TextRange* EF = P1->AppendText(L"Even Footer from E-iceblue Using Spire.Doc");
	EF->GetCharacterFormat()->SetFontName(L"Arial");
	EF->GetCharacterFormat()->SetFontSize(10);
	P1->GetFormat()->SetHorizontalAlignment(HorizontalAlignment::Center);

	//Save and launch document
	doc->SaveToFile(outputFile.c_str(), FileFormat::Docx);
	doc->Close();
	delete doc;
}
