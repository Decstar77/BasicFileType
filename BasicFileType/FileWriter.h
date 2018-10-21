#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include "InfoHeader.h"
#include "FileHeader.h"
#include "Person.h"

class FileWriter
{
	private:
		int AmtPerson;
		Person *persons;

	public:
		FileWriter(int AmountPerson = 8);
		~FileWriter();
		bool Write(std::string);
		void Print();
};

