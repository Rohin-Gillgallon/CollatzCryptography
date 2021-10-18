
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

void StrengthAnalysis::randomize(char arr[], int n)
{

	std::srand((int)std::time(0) * rand());
	for (int i = n - 1; i > 0; i--)
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
};

std::string StrengthAnalysis::SecondGroup()
{
	char group2[256];
	for (int i = 0; i < 256; i++)
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
	for (int i = 0; i < 256; i++)
	{
		words2 += group2[i];
	}
	return words2;
};