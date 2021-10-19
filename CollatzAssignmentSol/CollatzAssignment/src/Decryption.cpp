#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <chrono>
#include <any>
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
	return "abcdefghijklmnopqrstuvwxyz";
}

bool DecryptPasswords::decrypt(std::string& example, std::string& group, int groupno)
{
	int size = 1,  item, noletter = (groupno == 1) ? 27 : 256;
	std::string prefix, encpref, error = "error";
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
				return true;
		}
		size++;
		if (!example.starts_with(encpref))
			return false;
	}
	return false;
};

void Time(std::chrono::steady_clock::time_point start)
{
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration;
	duration = end - start;
	std::cout << "The decryption of these passwords took " << duration.count() << "s " << "\n";
}

void DecryptPasswords::DecryptCount(int start, int end)
{
	std::string line;
	std::ifstream read("passwordtest.txt");
	float count = 0;
	auto startTimer = std::chrono::high_resolution_clock::now();
	for (int i = start; std::getline(read, line) && i < end + 1; i++)
	{
		int groupno = (i < 10001) ? 1 : 2;
		std::string passwords = (groupno == 1) ? FirstGroup() : SecondGroup();
		if (decrypt(line, passwords, groupno))
			count++;
		if (i == (groupno * 10000))
		{
			std::cout << "The decryption percentage for the passwords in group " << groupno << " up to " << groupno << "0000 is: " << (count / 10000) * 100 << "% \n";
			Time(startTimer);
			startTimer = std::chrono::high_resolution_clock::now();
			count = 0;
			if (groupno == 2) return;
		}
	}
	read.close();
	return;
};
