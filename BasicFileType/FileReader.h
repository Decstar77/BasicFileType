#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "InfoHeader.h"
#include "FileHeader.h"
#include "Person.h"




class FileReader
{
	private:
		std::fstream *inFile;
		int sizeOfHeader;
		const char * FileName;

	public:
		FileReader(const char * fileName, std::fstream *file);
		~FileReader();
		bool FileReadName();
		bool PrepareToRead();
		int PassHeaders();
		int ReadInt(int *store, int pass, bool start = false);
		int ReadString(std::string * store, int pass, bool start = false);
		int ReadPerson(Person *store, int pass, bool start = false);
		int ReadFileHeader(FileHeader *header);
		int ReadInfoHeader(InfoHeader *header);
		int Test();

};

