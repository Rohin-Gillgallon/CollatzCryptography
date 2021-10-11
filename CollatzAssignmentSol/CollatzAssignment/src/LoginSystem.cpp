#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LoginSystem.h"


	void LoginSystem::reg()
	{
		std::string username, password;

		std::cout << "Select a username: ";
		std::cin >> username;
		std::cout << "Select a password: ";
		std::cin >> password;
		std::hash<std::string> Hash;

		std::ofstream file;
		file.open("login.txt");
		file << Hash(username) << " " << Hash(password) << "\n";
		file.close();

		system();
	};

	bool LoginSystem::Authorise()
	{
		std::string username, password, un, pw;

		std::cout << "Enter username: ";
		std::cin >> username;
		std::cout << "Enter password: ";
		std::cin >> password;
		std::hash<std::string> Hash;

		std::ifstream read("login.txt");
		std::string details[2];
		for (int i = 0; i < 2; i++)
		{
			read >> details[i];
		}

		if (details[0] == std::to_string(Hash(username)) && details[1] == std::to_string(Hash(password)))
		{
			std::cout << "True\n";
			return true;
		}
		else
		{
			std::cout << "False\n";
			return false;
		}
	}

	void LoginSystem::login()
	{
		bool status = Authorise();
		if (!status)
		{
			std::cout << "False Login!\n";
			passwordcount++;

			if (passwordcount == 3)
			{
				std::cout << "Locked out! Too many failed attempts!";
					return;
			}
			login();
		}
		else
		{
			std::cout << "Successfully logged in!\n";
		}
	}


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
		}
		else
		{
			std::cout << "Error! Please enter 1 or 2" << std::endl;
			system();
		}
	}

