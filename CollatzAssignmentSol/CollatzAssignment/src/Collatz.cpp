#include <iostream>
#include <fstream>
#include "Collatz.h"

Collatz::Collatz() {}
Collatz::~Collatz() {}

std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString)
{
	std::vector<signed int> encword(word.size());
	int offset = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int item = (int)word[i];
		if (item < 0)
			item += 256;
		int toASCII = item + offset;
		int count = 0;
		while (toASCII > 1)
		{
			if (toASCII % 2 == 0)
			{
				toASCII = toASCII / 2;
			}
			else if (toASCII % 2 == 1)
			{
				toASCII = (toASCII * 3) + 1;

			}
			count++;
		}
		encword[i] = count;
		offset = count;
	}
	std::string password;
	password = toString(encword);
	return password;
};

void Collatz::checkfile(std::string filename)
{
	try
	{
		std::ifstream file;
		file.open(filename);
		if (!file)
			throw false;
	}
	catch (bool& f)
	{
		std::cout << "The file required for this method does not exist!\n";
	}
};