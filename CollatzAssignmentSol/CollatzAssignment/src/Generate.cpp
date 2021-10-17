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

std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString);

static auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (size_t i = 0; i < encword.size(); ++i)
	{
		/*if (i != 0)
			hidden << ",";*/
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};

//void StrengthAnalysis::swap(char& a, char& b);
/* {
	char temp = a;
	a = b;
	b = temp;
};*/

//void StrengthAnalysis::randomize(char arr[], int n);
/* {
	// Use a different seed value so that
	// we don't get same result each time
	// we run this program
	std::srand((int)std::time(0) * rand());

	// Start from the last element and swap
	// one by one. We don't need to run for
	// the first element that's why i > 0
	for (int i = n - 1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = std::rand() % (i + 1);

		// Swap arr[i] with the element
		// at random index
		swap(arr[i], arr[j]);
	}
};*/

void Generate::write(std::string& word)
{
	if (std::fstream{ "passwordtest.txt" })
	{
		std::fstream file;
		file.open("passwordtest.txt", std::ios_base::app);
		file << encrypt(word, toString) << "\n";
		file.close();
		//std::cout << "File exists\n";
	}
	else
	{
		std::ofstream file;
		file.open("passwordtest.txt");
		file << encrypt(word, toString) << "\n";
		file.close();
		//std::cout << "File being created as one did not exist\n";
	}
};


/*template <typename T>
T random(T low, T high)
{
	srand((int)std::time(0) * rand() * (int)std::time(NULL));
	T randNum = (rand() % (high + 1 - low)) + low;
	return randNum;
};*/

//std::string StrengthAnalysis::FirstGroup();
/* {
	char group[10];
	char* GrpPtr = &group[0];
	srand((int)std::time(0) * rand());

	for (int i = 0; i < 10; i++)
	{
		char item = random(97, 122);
		*GrpPtr = item;
		//std::cout << item << std::endl;
		GrpPtr++;
	}

	std::string words;
	for (int i = 0; i < 10; i++)
	{
		words.push_back(group[i]);
		//std::cout << group[i];
	}
	return words;
};*/

//std::string StrengthAnalysis::SecondGroup();
/* {
	char group2[134];
	for (int i = 32; i < 166; i++)
	{
		group2[i - 32] = (char)i;
		//std::cout << i << ' ' << (char)i << std::endl;
	}

	srand((int)std::time(0) * rand());
	for (int i = 0; i < 7; i++)
		randomize(group2, sizeof(group2) / sizeof(group2[0]));
	//std::cout << "n= " << n << std::endl;);
	//random_shuffle(&group2[0], &group2[134]);
	std::string words2;
	for (int i = 0; i < 134; i++)
	{
		words2 += group2[i];
	}
	return words2;
};*/

void Generate::Gen1()
{
	std::string line;
	std::string radd = FirstGroup();
	/*srand((int)std::time(0));
	int ran = random(0, 100);*/
	int size = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			while (line.length() < size)
			{
				//srand((int)std::time(0) * rand());
				//random(0, 9)// (rand() % (122 + 1 - 97)) + 97;
				line.push_back(radd[random(0, 9)]);
			}
			std::cout << line.length() << ' ' << j + 1 << ' ' << line << std::endl;
			write(line);
			//line.pop_back();
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
	/*srand((int)std::time(0));
	int ran = random(0, 100);*/
	int size = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int k = 0;
			while (line.length() < size)
			{
				//srand((int)std::time(0) * rand());
				//random(0, 9)// (rand() % (122 + 1 - 97)) + 97;
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