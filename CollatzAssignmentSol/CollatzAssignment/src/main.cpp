#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
#include "Collatz.h"
#include "LoginSystem.h"

using namespace std;

int main()
{
	LoginSystem ls;
	ls.system();
	system("pause");
}
/*std::string encrypt(std::string word, const std::function<std::string(vector<int>)>& toString)
{
	vector<int> encword(word.size());
	int offset = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int toASCII = (int)word[i] + offset;
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
}

/*auto toString = [&](std::vector<int> encword) {
	std::stringstream hidden;
	for (size_t int i = 0; i < encword.size(); ++i)
	{
		if (i != 0)
			hidden << ",";
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};*/
