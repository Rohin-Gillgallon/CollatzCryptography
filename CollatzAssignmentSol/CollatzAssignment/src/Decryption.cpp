#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
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

bool DecryptPasswords::decrypt(std::string& example, std::string& group, int groupno)
{
	int size = 1;
	int item;
	int noletter = (groupno == 1) ? 27 : 134; //27;
	std::string prefix;
	std::string error = "error";
	std::string encpref;
	//std::string all = { "abcdefghijklmnopqrstuvwxyz" };
	for (int i = 0; i < example.length(); i++)
	{
		for (int j = 0; j < noletter/*all.size()*/; j++)
		{//system("pause");
			while (prefix.length() < size)
			{
				item = group[j];//(noletter == 134) ? (char)(j + 32) : (char)(j + 97);
				item = (item < 0) ? item += 256 : item;
				prefix += (char)item;//all[j];//;//example.starts_with(prefix) ? std::cout << "yes\n" : std::cout << "no\n";
			}
			encpref = encrypt(prefix, toString);
			//std::cout << prefix << std::endl;
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
		{
			//std::cout << error << "\n";
			return false; // (example == encpref) ? prefix : error;
		}
	}
	std::cout << error << "\n";
	return false;
};

int DecryptPasswords::DecryptCount(std::string& passwords)
{
	std::string line;
	std::ifstream read("passwordtest.txt");
	int lineno = 1;
	int count = 0;
	if (read.is_open())
	{
		for (int i = lineno; std::getline(read, line) && i < 1001; i++)
		{
			if (i == lineno)
			{
				if (decrypt(line, passwords, 2))
					count++;
				//std::cout << i << ' ' << decryptline.length() << ' ' << decryptline << std::endl;
			}
			lineno++;
		}
		read.close();
	}
	else std::cout << "Can not open the file";
	return count;
};

/*int main()
{
	std::string decryptline;
	std::string line = SecondGroup();
	int group = DecryptCount(line);//SecondGroup();
	std::cout << "The number of passwords decrypted is: " << group << std::endl;
	/*std::string sent = {"raarbxlbvaxaljjamygaahsfftwabl"};
	std::string encsent = encrypt(sent, toString);
	//std::string example = {"138765419879"};
	std::cout << encsent << std::endl;
	//std::cout << prefix << std::endl;
	//std::string decsent = decrypt(sent);
	//std::cout << "The password is " << decsent << std::endl;
	system("pause");
	return 0;
}*/