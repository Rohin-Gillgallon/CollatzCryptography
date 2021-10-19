#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include "Collatz.h"
#include "LoginSystem.h"

std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString);

	auto toString = [&](std::vector<int> encword) {
		std::stringstream hidden;
		for (/*size_t*/ int i = 0; i < encword.size(); ++i)
		{
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

		if (std::fstream{ "password.txt" })
		{
			std::fstream file;
			std::cout << "file exists\n";
			file.open("password.txt", std::ios_base::app);
			file << username << " " << ecpass << "\n";
			file.close();
		}
		else
		{
			std::ofstream file;
			file.open("password.txt");
			file << username << " " << ecpass << "\n";
			file.close();
			std::cerr << "File being created as one did not exist\n";
		}
		system();
	};

	void LoginSystem::login()
	{
		std::cout << "Enter username: ";
		std::cin >> username;
		if (ReadData(username))
		{
			std::cout << "Valid username, please now enter your password!\n";
			Password();
			return;
		}
		std::cout << "Failure, non-valid username, please try again!\n";
		login();
	}

	bool LoginSystem::ReadData(std::string& username)
	{
		std::string line;
		checkfile("password.txt");
		std::ifstream read("password.txt");
		while (std::getline(read, line, ' '))
		{
			if (line.find(username) != std::string::npos)
			{
				if (username == line)
				{
					details[0] = username;
					read >> details[1];
					return true;
				}
				else
				{
					return false;
				}
			}
		read.ignore(256, '\n');
		}
		return false;
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
