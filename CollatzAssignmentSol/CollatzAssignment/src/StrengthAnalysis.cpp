
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

void StrengthAnalysis::swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
};

void StrengthAnalysis::randomize(char arr[], int size)
{
	std::srand((int)std::time(0) * rand());
	for (int i = size - 1; i > 0; i--)
	{
		int j = std::rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
};

std::string StrengthAnalysis::FirstGroup()
{
	char group[10];
	char* GrpPtr = &group[0];
	srand((int)std::time(0) * rand());

	for (int i = 0; i < 10; i++)
	{
		char item = random(97, 122);
		*GrpPtr = item;
		GrpPtr++;
	}

	std::string words;
	for (int i = 0; i < 10; i++)
	{
		words.push_back(group[i]);
	}
	return words;
};

std::string StrengthAnalysis::SecondGroup()
{
	char group2[256];
	for (int i = 0; i < 256; i++)
	{
		group2[i] = (char)i;
	}

	srand((int)std::time(0) * rand());
	for (int i = 0; i < 7; i++)
		randomize(group2, sizeof(group2) / sizeof(group2[0]));
	std::string words2;
	for (int i = 0; i < 256; i++)
	{
		words2 += group2[i];
	}
	return words2;
};

void StrengthAnalysis::System()
{
	int choice;
	std::cout << "Now please select:\n1. Password Generation\n2. Password Discovery\n";
	std::cin >> choice;
	if (choice == 1)
	{
		std::ifstream file;
		file.open("passwordtest.txt");
		if (file)
		{
			std::string del;
			std::cout << "A file containing passwords already exists\nWould you like to clear the file and generate new passwords?\nEnter yes or no...\n";
			std::cin >> del;
			if (del == "yes" || del == "y")
			{
				std::ofstream delfile;
				delfile.open("passwordtest.txt", std::ofstream::out | std::ofstream::trunc);
				delfile.close();
				Generate g;
				g.System();
				std::string cont;
				std::cout << "Do you want to discover these passwords:\nyes or no?";
				std::cin >> cont;
				if (cont == "yes" || cont == "y")
				{
					DecryptPasswords Dec;
					Dec.System();
				}
				else if (cont == "no" || cont == "n")
				{
					return;
				}
				else
				{
					std::cout << "Invalid entry, returning to previous menu\n";
					return;
				}
			} 
			else
			{
				System();
			}
		}
		else
		{
			Generate g;
			g.System();
			std::string cont;
			std::cout << "Do you want to decrypt these passwords:\nyes or no?\n";
			std::cin >> cont;
			if (cont == "yes" || cont == "y")
			{
				DecryptPasswords Dec;
				Dec.System();
			}
			else if (cont == "no" || cont == "n")
			{
				return;
			}
			else
			{
				std::cout << "Invalid entry, returning to previous menu\n";
				return;
			}
		}
	}
	if (choice == 2)
	{
		DecryptPasswords Dec;
		Dec.System();
		std::cout << "\nReturning to previous menu...\n";
		return;
	}
}