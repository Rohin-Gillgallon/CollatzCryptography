#include <iostream>
#include <fstream>
#include <any>
#include "Collatz.h"
#include "LoginSystem.h"
#include "StrengthAnalysis.h"

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

bool Collatz::checkfile(std::string filename)
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
		return false;
	}
	return true;
};

void Collatz::System()
{
	std::any var = true;
	if (std::any_cast<bool>(var))
	{
		int choice;
		std::string select = "Please select:\n";
		std::cout << select;
		var = 1;
		std::cout << std::any_cast<int>(var);
		std::string login = ". Login System\n";
		std::cout << login;
		var = 2;
		std::cout << std::any_cast<int>(var);
		std::string psa = ". Password Strength Analysis\n";
		std::cout << psa;
		var = 3;
		std::cout << std::any_cast<int>(var);
		std::string exit = ". Exit\n";
		std::cout << exit;
		
		std::cin >> choice;
		if (choice == 1)
		{
			LoginSystem ls;
			ls.System();
			std::cout << "\n";
			System();
		}
		else if (choice == 2)
		{
			StrengthAnalysis sa;
			sa.System();
			std::cout << "\n";
			System();
		}
		else if (choice == 3)
		{
			var = false;
		}
		else
		{
			std::cout << "Invalid number input, please try again choosing either 1 or 2\n";
			system("pause");
			std::cout << "\n";
			System();
		}
	}
	else
		return;
}