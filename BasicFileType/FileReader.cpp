#include "stdafx.h"
#include "FileReader.h"


FileReader::FileReader(const char *fileName, std::fstream *file)
{
	this->FileName = fileName;
	this->inFile = file;
	this->sizeOfHeader = sizeof(FileHeader) + sizeof(InfoHeader);
}
FileReader::~FileReader()
{
}
bool FileReader::PrepareToRead()
{
	if (!inFile->is_open())
	{
		std::cout << "File is not open" << std::endl;
		return false;
	}
	return true;
}
int FileReader::PassHeaders()
{
	inFile->seekp(0, std::ios::beg);
	inFile->ignore(sizeOfHeader);
	return sizeOfHeader;
}
int FileReader::ReadInt(int *store, int pass, bool start)
{
	int SizeOfInt = sizeof(int);
	if (start) { inFile->seekp(0, std::ios::beg); }
	inFile->ignore(pass);
	char *buffer = new char[SizeOfInt];
	inFile->read(buffer, SizeOfInt);
	memcpy(store, &buffer[0], SizeOfInt);
	//std::cout << "Gif: " << *store << std::endl;
	delete buffer;
	return SizeOfInt;
}
int FileReader::ReadString(std::string *store, int pass, bool start)
{
	int stringSize;
	int SizeOfInt = sizeof(int);
	char *buffer = new char[SizeOfInt];
	inFile->read(buffer, SizeOfInt);
	memcpy(&stringSize, &buffer[0], SizeOfInt);
	//std::cout << "StringSize: " << stringSize << std::endl;

	char *stringBuffer = new char[stringSize];
	inFile->read(stringBuffer, stringSize);
	std::cout << "Name " << stringBuffer << std::endl;
	*store = stringBuffer;
	delete stringBuffer;
	delete buffer;
	return stringSize;
}
int FileReader::ReadPerson(Person *store, int pass, bool start)
{
	if (start) { inFile->seekp(0, std::ios::beg); }
	inFile->ignore(pass);
	int CurrentPos = inFile->tellg();
	int SizeOfPerson;
	ReadInt(&SizeOfPerson, 0);
	inFile->seekg(CurrentPos);
	int EndPos = 0;
	//ReadThePerson
	char *buffer = new char[SizeOfPerson];
	inFile->read(buffer, SizeOfPerson);
	EndPos = inFile->tellg();
	memcpy(store, &buffer[0], SizeOfPerson);
	//ReadThePersonName
	inFile->seekg(CurrentPos);
	inFile->ignore(12);
	char *stringBuffer = new char[store->GetNameSize()]; //GetSize is bad. It gets the whole size of the person.
	inFile->read(stringBuffer, store->GetNameSize());
	store->SetName(stringBuffer, store->GetNameSize());
	inFile->seekg(EndPos);

	//Delete Buffers
	delete stringBuffer;
	delete buffer;
	return SizeOfPerson;
}
int FileReader::ReadFileHeader(FileHeader *header)
{
	inFile->seekp(0, std::ios::beg);
	int FileHeaderSize = sizeof(FileHeader);
	char *buff = new char[FileHeaderSize];
	inFile->read(buff, FileHeaderSize);
	memcpy(header, &buff[0], FileHeaderSize);
	return FileHeaderSize;
}
int FileReader::ReadInfoHeader(InfoHeader *header)
{
	inFile->seekp(0, std::ios::beg);
	inFile->ignore(sizeof(FileHeader));
	int InfoHeaderSize = sizeof(InfoHeader);
	char *buff = new char[InfoHeaderSize];
	inFile->read(buff, InfoHeaderSize);
	memcpy(header, &buff[0], InfoHeaderSize);
	return InfoHeaderSize;
}
int FileReader::Test()
{
	inFile->seekg(0, std::ios::beg);
	inFile->ignore(sizeof(FileHeader));
	char * buffer = new char[sizeof(InfoHeader)];
	inFile->read(buffer, sizeof(InfoHeader));
	int temp;
	memcpy(&temp, &buffer[0], 4);
	std::cout << temp << std::endl;
	return 0;
}
bool FileReader::FileReadName()
{
	/*
	int age;
	std::fstream inFile;
	inFile.open(FileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (!inFile) {
		std::cout << "Errr" << std::endl;
		return false;
	}
	void *mem = malloc(4);
	int i = 3;
	memcpy(&mem, &i, 4);
	std::cout << mem << std::endl;
	//Gets the header files
	//inFile.seekp(0, std::ios::beg);
	//char *buffer = new char[size];
	//inFile.read(buffer, size);
	//memcpy(&age, &buffer[8], sizeof(int));	
	//std::cout << "Age: " << size << " " << age << std::endl;

	//TypeCastFileHeader
	FileHeader fHead;
	inFile.seekp(0, std::ios::beg);
	int FileHeaderSize = sizeof(FileHeader);
	char *buff = new char[FileHeaderSize];
	inFile.read(buff, FileHeaderSize);
	memcpy(&fHead, &buff[0], FileHeaderSize);
	std::cout << "Sup: " << fHead.fileSize << std::endl;

	inFile.seekp(0, std::ios::beg);
	inFile.ignore(size);
	char *buff = new char[4];
	inFile.read(buff, 4);
	memcpy(&age, &buff[0], 4);
	std::cout << "Gif: " << age << std::endl;

	int stringSize;
	inFile.read(buff, 4);
	memcpy(&stringSize, &buff[0], 4);
	std::cout << "StringSize: " << stringSize << std::endl;

	char *stringBuffer = new char[stringSize];
	inFile.read(stringBuffer, stringSize);
	std::cout << "Name " << stringBuffer << std::endl;

	//TypeCastInforHeader
	//InfoHeader ihead;
	//inFile.seekp(0, std::ios::beg);
	//inFile.ignore(sizeof(FileHeader));
	//int InfoHeaderSize = sizeof(InfoHeader);
	//char *ibuff = new char[InfoHeaderSize];
	//inFile.read(ibuff, InfoHeaderSize);
	//memcpy(&ihead, &ibuff[0], InfoHeaderSize);
	//std::cout << "Oldest offset: " << ihead.Oldest << std::endl;

	//inFile.seekp(0, std::ios::beg);
	//inFile.ignore(ihead.Oldest);
	//char *ageBuff = new char[4];
	//inFile.read(ageBuff, 4);
	//memcpy(&age, &ageBuff[0], 4);
	//std::cout << "Age oldest: " << age << std::endl;
	//
	//inFile.read(ageBuff, 4);
	//memcpy(&age, &ageBuff[0], 4);
	//std::cout << "String Size: " << age << std::endl;

	//char *stringBuffer = new char[age];
	//inFile.read(stringBuffer, age);
	//std::cout << "name of oldest: " << stringBuffer << std::endl;

	//delete ibuff;
	//delete buff;
	//delete ageBuff;
	//delete buffer;	
	inFile.close();
	*/
	return false;
}
