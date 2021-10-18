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

std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString);
/* {
	std::vector<signed int> encword(word.size());
	int offset = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int item = (int)word[i];
		if (item < 0)
			item += 255;
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
}*/

static auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (int i = 0; i < encword.size(); ++i)
	{
		/*if (i != 0)
			hidden << ",";*/
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
	int size = 1;
	int item;
	int noletter = (groupno == 1) ? 27 : 256; // 134;
	std::string prefix;
	std::string error = "error";
	std::string encpref;
	//std::string all = { "abcdefghijklmnopqrstuvwxyz" };
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
				//std::cout << i + 1 << ' ' << prefix << std::endl;
				return true;
			}
		}
		size++;
		if (!example.starts_with(encpref))
		{
			//std::cout << error << "\n";
			return false;
		}
	}
	//std::cout << error << "\n";
	return false;
};

void DecryptPasswords::DecryptCount(int start, int end)
{
	std::string line;
	std::ifstream read("passwordtest.txt");
	float count = 0;
	std::chrono::steady_clock::time_point startTimer, middleTimer, endTimer;
	std::chrono::duration<float> duration;
	if (read.is_open())
	{
		startTimer = std::chrono::high_resolution_clock::now();
		for (int i = start; std::getline(read, line) && i < end + 1; i++)
		{
			if (i == start)
			{
				int groupno = (i < 10001) ? 1 : 2;
				std::string passwords = (groupno == 1) ? FirstGroup() : SecondGroup();
				//std::cout << i << ' ';
				if (decrypt(line, passwords, groupno))
					count++;
			}
			if (i == 10000)
			{
				std::cout << "The decryption percentage for the first 10000 passwords is: " << (count/10000) * 100 << "%\n";
				middleTimer = std::chrono::high_resolution_clock::now();
				duration = middleTimer - startTimer;
				std::cout << "The decryption of these passwords took " << duration.count() << "s " << "\n";
				count = 0;
			}
			if (i == 20000)
			{
				std::cout << "The decryption percentage for the second 10000 passwords is: " << (count / 10000) * 100 << "%\n";
				endTimer = std::chrono::high_resolution_clock::now();
				duration = endTimer - middleTimer ;
				std::cout << "The decryption of these passwords took " << duration.count() << "s " << "\n";
				return;
			}
			start++;
		}
		read.close();
	}
	else std::cout << "Can not open the file";
	return;
};