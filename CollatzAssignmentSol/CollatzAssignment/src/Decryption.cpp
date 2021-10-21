#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <chrono>
#include "Collatz.h"
#include "StrengthAnalysis.h"
#include "Decryption.h"

std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString);

static auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (int i = 0; i < encword.size(); ++i)
	{
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};

std::string DecryptPasswords::FirstGroup()
{
	char group[26];
	for (int i = 0; i < 26; i++)
	{
		group[i] = (char)i + 97;
	}

	srand((int)std::time(0) * rand());
	for (int i = 0; i < 7; i++)
		randomize(group, sizeof(group) / sizeof(group[0]));
	std::string words;
	for (int i = 0; i < 26; i++)
	{
		words += group[i];
	}
	return words;
}

bool DecryptPasswords::decrypt(std::string& example, std::string& group, int groupno)
{
	int size = 1,  item, noletter = (groupno == 1) ? 27 : 256;
	std::string prefix, encpref;
	for (int i = 0; i < example.length(); i++)
	{
		for (int j = 0; j < noletter; j++)
		{
			while (prefix.length() < size)
			{
				item = group[j];
				item = (item < 0) ? item += 256 : item;
				prefix += (char)item;
			} 
			encpref = encrypt(prefix, toString);
			if (!example.starts_with(encpref))
				prefix.pop_back();
			 if (example == encpref)
			{
				//std::cout << prefix << "\n";
				return true;
			}
		}
		size++;
		if (!example.starts_with(encpref))
			return false;
	}
	return false;
};

static auto Time = [&](std::chrono::steady_clock::time_point start)
{
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration;
	duration = end - start;
	std::cout << "The discovery of these passwords took on average " << duration.count()/100.00f << "s per password" << "\n" << "\n";
};

void DecryptPasswords::DecryptCount()
{
	std::string line;
	if (checkfile("passwordtest.txt"))
	{
		std::ifstream read("passwordtest.txt");
		int from = 1;
		int count = 0;
		int length = 1;
		auto startTimer = std::chrono::high_resolution_clock::now();
		for (int i = 1; std::getline(read, line) && i <= 20000; i++)
		{
			int groupno = (i < 10001) ? 1 : 2;
			std::string group = (groupno == 1) ? FirstGroup() : SecondGroup();
			if (decrypt(line, group, groupno))
				count++;
			if (i % 100 == 0) 
			{

					std::cout << "The percentage of the passwords of length " << length << " discovered in group " << groupno << " is: " <<((float)count / 100.00f) * 100.00f << "%\n";
					from += 100;
					length++;
					Time(startTimer);
					startTimer = std::chrono::high_resolution_clock::now();
					count = 0;
					length = (i == 10000) ? 1 : length;
			}
		}
		read.close();
		return;
	}
	else return;
};

void DecryptPasswords::System()
{
	std::cout << "Please wait whilst the passwords are being discovered...\n";
	DecryptCount();
}
