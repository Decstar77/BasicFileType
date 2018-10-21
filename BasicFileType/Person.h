#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#pragma(2)


class Person
{
	private:
		int32_t PersonSize = 0; // Order Does not matter, the way you write them does
		int32_t age;
		int32_t NameSize = 0;
		char* Name;		

	public:
		Person();
		~Person();
		void WriteData(std::ofstream *);
		void DisplayInfo(std::string prefix = "---BEGIN---", std::string sufix = "----END----");

		std::string GetName();
		int GetSize();
		int GetNameSize() { return NameSize; };
		int GetAge() { return age; }
		void SetAge(int set) { age = set; }
		void SetName(const char* name, int size);
};