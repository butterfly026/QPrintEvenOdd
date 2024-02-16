#include "pch.h"
using namespace Spire::Doc;

int main() {
	wstring input_path = DATAPATH;
	wstring inputFile = input_path + L"TableTemplate.docx";
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path + L"AddTableCaption.docx";

	//Create word document
	Document* document = new Document();
	//Load file
	document->LoadFromFile(inputFile.c_str());

	//Get the first table
	Body* body = document->GetSections()->GetItem(0)->GetBody();
	Table* table = dynamic_cast<Table*>(body->GetTables()->GetItemInTableCollection(0));

	//Add caption to the table
	table->AddCaption(L"Table", CaptionNumberingFormat::Number, CaptionPosition::BelowItem);

	//Update fields
	document->SetIsUpdateFields(true);

	//Save the Word document
	document->SaveToFile(outputFile.c_str(), FileFormat::Docx2013);
	document->Close();
	delete document;
}
