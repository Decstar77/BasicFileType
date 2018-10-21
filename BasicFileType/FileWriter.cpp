#include "stdafx.h"
#include "FileWriter.h"


FileWriter::FileWriter(int AmountPerson)
{	
	AmtPerson = AmountPerson;
	persons = new Person[AmountPerson];
	persons[0].SetName("Alia", sizeof("Alia"));
	persons[1].SetName("Mari", sizeof("Mari"));
	persons[2].SetName("Carey", sizeof("Carey"));
	persons[3].SetName("Uma", sizeof("Uma"));
	persons[4].SetName("Elizabeth", sizeof("Elizabeth"));
	persons[5].SetName("Declan", sizeof("Declan"));
	persons[6].SetName("Chad", sizeof("Chad"));
	persons[7].SetName("Steven", sizeof("Steven"));

	persons[0].SetAge(21);
	persons[1].SetAge(19);
	persons[2].SetAge(21);
	persons[3].SetAge(19);
	persons[4].SetAge(19);
	persons[5].SetAge(20);
	persons[6].SetAge(19);
	persons[7].SetAge(26);

	std::cout << "Created" << std::endl;
}

FileWriter::~FileWriter()
{
	std::cout << "Destoryed" << std::endl;
}

bool FileWriter::Write(std::string fileName)
{
#pragma region //OpenFile
	//Open File
	std::ofstream file;
	file.open(fileName, std::ios::out | std::ios::binary);
	if (!file)
		return false;
#pragma endregion
	//CreateHeaders
	FileHeader fheader;
	InfoHeader iheader;
	fheader.fileSize = 0;
	iheader.BoysOffset = 0;
	iheader.AmountOfPerson = 8;
	for (int i = 0; i < AmtPerson; i++)
	{
		fheader.fileSize += persons[i].GetSize();
	}
	fheader.headersSize = sizeof(FileHeader) + sizeof(InfoHeader);
	fheader.dataOffset = sizeof(FileHeader) + sizeof(InfoHeader);
	for (int i = 0; i < 5; i++)
	{
		iheader.BoysOffset += persons[i].GetSize();
	}
	iheader.BoysOffset += fheader.headersSize;
	iheader.GirlsOffset = fheader.dataOffset;
	iheader.OldestPersonOffset = fheader.dataOffset;
	for (int i = 0; i < 7; i++)
	{
		iheader.OldestPersonOffset += persons[i].GetSize();
	}

	//Write data	
	file.write(reinterpret_cast<char*>(&fheader), sizeof(fheader));
	file.write(reinterpret_cast<char*>(&iheader), sizeof(iheader));
	for (int i = 0; i < AmtPerson; i++)
	{
		persons[i].WriteData(&file);
	}

	file.close();
	if (!file)
		return false;
	return true;
}

void FileWriter::Print()
{
	std::cout << "Hectic" << std::endl;
}
