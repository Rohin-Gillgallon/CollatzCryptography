#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
#include "Collatz.h"
#include "LoginSystem.h"
#include "StrengthAnalysis.h"
#include "Generate.h"
#include "Decryption.h"

using namespace std;

std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString);

static auto toString = [&](std::vector<int> encword)
{
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

int main()
{
	//LoginSystem ls;
	//ls.system();
	//Generate g;
	//g.Gen1();
	//g.Gen2();
	DecryptPasswords Dec;
	std::string line = Dec.SecondGroup();
	int count = Dec.DecryptCount(line);
	std::cout << "The number of passwords decrypted is: " << count << std::endl;
	/*std::string all = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !\"#$%^&*(){}[];:'@~,<.>//|*-+"};
	std::string sent = {"A friend to all is a friend to none"};
	cout << encrypt(sent, toString) << "\n";
	/*for (int i = 0; i < all.size(); i++)
	{
		cout << all[i] << ' ' << encrypt(sent + all[i], toString) << "\n";
	}*/
	system("pause");
}