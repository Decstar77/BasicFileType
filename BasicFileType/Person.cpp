#include "stdafx.h"
#include "Person.h"



Person::Person()
{

}
Person::~Person()
{
	
}
void Person::WriteData(std::ofstream *stream)
{
	PersonSize = GetSize();
	std::cout << "Writing Name: " <<  Name << " Of size: " << PersonSize << std::endl;
	stream->write(reinterpret_cast<char*>(&PersonSize), sizeof(PersonSize));
	stream->write(reinterpret_cast<char*>(&age), sizeof(age));
	stream->write(reinterpret_cast<char*>(&NameSize), sizeof(NameSize));
	stream->write(reinterpret_cast<char*>(&Name[0]), NameSize);
}
void Person::DisplayInfo(std::string prefix, std::string sufix)
{
	std::cout << prefix << std::endl;
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << sufix << std::endl;
}
void Person::SetName(const char* name, int size)
{
	char *buffer = new char[size];
	strcpy_s(buffer, size, name);
	//std::cout << "In person: SetName() "<< buffer << std::endl;
	Name = buffer;	
	NameSize = size;
}
int Person::GetSize()
{
	return sizeof(int32_t) * 3 + NameSize;
}
std::string Person::GetName()
{
	std::string name = Name;
	return name;
}