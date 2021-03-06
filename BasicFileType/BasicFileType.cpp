// BasicFileType.cpp : Defines the entry point for the console application.
//
#include <windows.h>
#include "stdafx.h"
#include "FileWriter.h"
#include "FileReader.h"

int main()
{
	std::string name = "Test.dm";
	bool done = false;
	std::string command;
	std::cout << "Write test data ? " << std::endl;
	std::cin >> command;
	switch (command[0])
	{
		case 'y':
		case 'Y':
			{
				std::cout << "Writing test data" << std::endl;
				FileWriter *writer = new FileWriter();
				writer->Write(name); system("PAUSE"); return 0;
			}
		case 'n':
		case 'N': std::cout << "Looking for test data " << std::endl; break;
	}
	Sleep(1000);
	std::fstream inFile; 
	inFile.open(name, std::ios::in | std::ios::binary | std::ios::ate);		
	FileReader *fileReader = new FileReader(name.c_str(), &inFile);
	std::cout << "Current file: " << name << std::endl;
	std::cout << "Preparing to read: " << std::endl;
	Sleep(1000);
	done = fileReader->PrepareToRead();
	if (!done)
	{ 
		std::cout << "Unable to read" << std::endl;	
		system("PAUSE");
		delete fileReader;
		return 0;
	}
	std::cout << "Reading info header" << std::endl;
	Sleep(1000);
	InfoHeader ihead;
	fileReader->ReadInfoHeader(&ihead);
	std::cout << "Amount of people: " << ihead.AmountOfPerson << std::endl;
	Sleep(2000);
	std::cout << "Passing headers: " << fileReader->PassHeaders() << std::endl;
	Sleep(2000);
	std::cout << "Loading people..." << std::endl;
	int amt = ihead.AmountOfPerson;
	Person *people = new Person[amt];
	for (int i = 0; i < amt; i++)
	{
		fileReader->ReadPerson(&people[i], 0);
	}
	Sleep(5000);
	std::cout << "Success" << std::endl;
	std::cout << "Displaying people - Ordered female to male" << std::endl;
	Sleep(100);
	for (int i = 0; i < amt; i++)
	{
		people[i].DisplayInfo();
	}
	std::cout << "--END--" << std::endl;
	//delete p1, p2, p3;
	inFile.close();
	delete fileReader;
	//delete personArray;
	system("PAUSE");
    return 0;
}

