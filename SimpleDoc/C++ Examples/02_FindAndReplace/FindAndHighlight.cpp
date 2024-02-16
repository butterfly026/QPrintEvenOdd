#include "pch.h"
using namespace Spire::Doc;
using namespace Spire::Common;

int main(){
	wstring input_path = DATAPATH;
	wstring inputFile = input_path + L"Sample.docx";
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path +L"FindAndHighlight.docx";

	//Create word document
	Document* document = new Document();

	//Load the document from disk.
	document->LoadFromFile(inputFile.c_str());

	//Find text
	vector<TextSelection*> textSelections = document->FindAllString(L"word", false, true);

	//Set hightlight
	for (auto selection : textSelections)
	{
		selection->GetAsOneRange()->GetCharacterFormat()->SetHighlightColor(Color::GetYellow());
	}

	//Save doc file.
	document->SaveToFile(outputFile.c_str(), FileFormat::Docx);
	document->Close();
	delete document;
}
