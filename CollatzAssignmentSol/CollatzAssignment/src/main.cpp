#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
#include "Collatz.h"
#include "LoginSystem.h"

using namespace std;


std::string encrypt(std::string word, const std::function<std::string(vector<int>)>& toString)
{
	vector<int> encword(word.size());
	for (int i = 0; i < word.size(); i++)
	{
		int toASCII = (int)word[i];
		if (toASCII % 2 == 0)
		{
			encword[i] = toASCII / 2;
			//cout << encword[i] << "\n";
			//return toASCII / 2;
		}
		else if (toASCII % 2 == 1)
		{
			encword[i] = (toASCII * 3) + 1;
			//cout << encword[i] << "\n";
			//return (toASCII * 3) + 1;
		}
	}
	std::string password;
	password = toString(encword);
	return password;
}

auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (/*size_t*/ int i = 0; i < encword.size(); ++i)
	{
		if (i != 0)
			hidden << ",";
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};

int main()
{
	/*LoginSystem ls;
	ls.system();
	system("pause");*/
	std::string word = "cat";
	//vector<int> encword(word.size());
	auto q = encrypt(word, toString);
	cout << q << "\n";


	/*for (int i = 0; i < word.size(); i++)
	{
		encword[i] = encrypt(word[i]);
		cout << encword[i] << "\n";
	}*/

	system("pause");
}