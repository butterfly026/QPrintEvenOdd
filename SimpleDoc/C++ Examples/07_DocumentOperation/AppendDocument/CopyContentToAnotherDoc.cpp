#include "pch.h"
using namespace Spire::Doc;

int main() {
	wstring input_path = DATAPATH;
	wstring inputFile_1 = input_path + L"Template_Docx_1.docx";
	wstring inputFile_2 = input_path + L"Target.docx";
	wstring output_path = OUTPUTPATH;
	wstring outputFile = output_path + L"CopyContentToAnotherDoc.docx";

	//Initialize a new object of Document class and load the source document.
	Document* sourceDoc = new Document();
	sourceDoc->LoadFromFile(inputFile_1.c_str());

	//Initialize another object to load target document.
	Document* destinationDoc = new Document();
	destinationDoc->LoadFromFile(inputFile_2.c_str());

	//Copy content from source file and insert them to the target file.
	int sectionCount = sourceDoc->GetSections()->GetCount();
	for (int i = 0; i < sectionCount; i++)
	{
		Section* sec = sourceDoc->GetSections()->GetItem(i);
		int sectionChildObjectsCount = sec->GetBody()->GetChildObjects()->GetCount();
		for (int j = 0; j < sectionChildObjectsCount; j++)
		{
			DocumentObject* documentObject = sec->GetBody()->GetChildObjects()->GetItem(j);
			destinationDoc->GetSections()->GetItem(0)->GetBody()->GetChildObjects()->Add(documentObject->Clone());
		}
	}

	//Save to file.
	destinationDoc->SaveToFile(outputFile.c_str(), FileFormat::Docx2013);
	sourceDoc->Close();
	destinationDoc->Close();
	delete sourceDoc;
	delete destinationDoc;
}

