#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "Collatz.h"
#include "StrengthAnalysis.h"
#include "Generate.h"
#include "Decryption.h"

std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString);

static auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (size_t i = 0; i < encword.size(); ++i)
	{
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};

void Generate::write(std::string& word)
{
	if (std::fstream{ "passwordtest.txt" })
	{
		std::fstream file;
		file.open("passwordtest.txt", std::ios_base::app);
		file << encrypt(word, toString) << "\n";
		file.close();
	}
	else
	{
		std::ofstream file;
		file.open("passwordtest.txt");
		file << encrypt(word, toString) << "\n";
		file.close();
	}
};

void Generate::Gen1()
{
	std::string line;
	std::string radd = FirstGroup();
	int size = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			while (line.length() < size)
			{
				line.push_back(radd[random(0, 9)]);
			}
			std::cout << line.length() << ' ' << j + 1 << ' ' << line << std::endl;
			write(line);
			line.erase();
			radd = FirstGroup();
		}
		size++;
	}
	return;
};

void Generate::Gen2()
{
	std::string line;
	std::string radd = SecondGroup();
	int size = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int k = 0;
			while (line.length() < size)
			{
				line.push_back(radd[k]);
				k++;
			}
			std::cout << line.length() << ' ' << j + 1 << ' ' << line << std::endl;
			write(line);
			//line.pop_back();
			line.erase();
			radd = SecondGroup();
		}
		size++;
	}
	return;
};