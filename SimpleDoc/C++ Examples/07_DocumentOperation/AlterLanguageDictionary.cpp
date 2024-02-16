#include "pch.h"
using namespace Spire::Doc;

int main() {
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path + L"AlterLanguageDictionary.docx";

	//Create Word document.
	Document* document = new Document();

	//Add new section and paragraph to the document.
	Section* sec = document->AddSection();
	Paragraph* para = sec->AddParagraph();

	//Add a textRange for the paragraph and append some Peru Spanish words.
	TextRange* txtRange = para->AppendText(L"corrige según diccionario en inglés");
	txtRange->GetCharacterFormat()->SetLocaleIdASCII(10250);

	//Save to file.
	document->SaveToFile(outputFile.c_str(), FileFormat::Docx2013);
	document->Close();
	delete document;
}