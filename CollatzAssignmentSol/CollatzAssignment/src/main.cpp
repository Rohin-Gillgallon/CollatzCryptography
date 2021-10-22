#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "Collatz.h"
#include "LoginSystem.h"
#include "StrengthAnalysis.h"
#include "Generate.h"
#include "Decryption.h"

using namespace std;

/*std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)> toString)
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

static auto toString = [&](std::vector<int> encword)
{
	std::stringstream hidden;
	for (int i = 0; i < encword.size(); ++i)
	{
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};*/

int main()
{
	unique_ptr<Collatz> C = make_unique<Collatz>();
	C->System();

	/*std::string all = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !\"#$%^&*(){}[];:'@~,<.>//|*-+"};
	std::string sent = {"A friend to all is a friend to none"};
	std::string code = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	//for (int i = 0; i < 256; i++)
	//{
		cout << encrypt(sent, toString) << "\n";
	//}
	if (encrypt(sent, toString) == code)
		cout << "TRUE!\n";
	else
		cout << "FALSE!\n";*/
	//system("pause");
}