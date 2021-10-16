#include <iostream>
#include "Collatz.h"

Collatz::Collatz() {}
Collatz::~Collatz() {}

std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString)
{
	std::vector<signed int> encword(word.size());
	int offset = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int item = (int)word[i];
		if (item < 0)
			item += 256;
		int toASCII = item + offset;
		//cout << "ASCII " << toASCII << ' ';
		int count = 0;
		while (toASCII > 1)
		{
			if (toASCII % 2 == 0)
			{
				toASCII = toASCII / 2;
				//cout << encword[i] << "\n";
				//return toASCII / 2;
			}
			else if (toASCII % 2 == 1)
			{
				toASCII = (toASCII * 3) + 1;
				//cout << encword[i] << "\n";
				//return (toASCII * 3) + 1;
			}
			count++;
		}
		encword[i] = count;
		offset = count;
		//cout << "offset " << offset << ' ';
	}
	std::string password;
	password = toString(encword);
	return password;
};