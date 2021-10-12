#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Collatz.h"
#include "LoginSystem.h"

	std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString)
	{
		std::vector<int> encword(word.size());
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

	auto toString = [&](std::vector<int> encword) {
		std::stringstream hidden;
		for (/*size_t*/ int i = 0; i < encword.size(); ++i)
		{
			/*if (i != 0)
				hidden << ",";*/
			hidden << encword[i];
		}
		std::string encpass = hidden.str();
		return encpass;
	};

	void LoginSystem::system()
	{
		int choice;
		std::cout << "Register: 1\nLogin: 2\nEnter choice... ";
		std::cin >> choice;
		if (choice == 1)
		{
			reg();
		}
		else if (choice == 2)
		{
			login();
			return;
		}
		else
		{
			while (std::cin.fail()) {
				std::cout << "Error! Please enter 1 or 2!\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				system();
			}
			std::cout << "\n";
			system();
		}
	}

	void LoginSystem::reg()
	{
		std::string username, password;

		std::cout << "Select a username: ";
		std::cin >> username;
		std::cout << "Select a password: ";
		std::cin >> password;
		std::string ecpass = encrypt(password, toString);

		std::ofstream file;
		file.open("login.txt");
		file << username << " " << ecpass << "\n";
		file.close();

		system();
	};

	void LoginSystem::login()
	{
		ReadData();
		std::cout << "Enter username: ";
		std::cin >> username;
		if (details[0] == username)
		{
			std::cout << "Valid username, please now enter your password!\n";
			Password();
			return;
		}
		std::cout << "Failure, non-valid username, please try again!\n";
		login();
	}

	void LoginSystem::ReadData()
	{
		std::ifstream read("login.txt");
		for (int i = 0; i < 2; i++)
		{
			read >> details[i];
		}
	}

	void LoginSystem::Password()
	{
		std::cout << "Enter password: ";
		std::cin >> password;

		bool status = (details[1] == encrypt(password, toString));
	
		if (!status)
		{
			std::cout << "False Login! ";
			passwordcount++;
			std::cout << 3 - passwordcount << " attempts remaining!\n";
			if (passwordcount == 3)
			{
				std::cout << "Locked out! Too many failed attempts!\n";
				return;
			}
			Password();
		}
		else
		{
			std::cout << "Successfully logged in!\n";
			return;
		}
	}
