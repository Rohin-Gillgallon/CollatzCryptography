#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LoginSystem.h"

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
		file << username << " " << Hash(password) << "\n";
		file.close();

		system();
	};

	void LoginSystem::ReadData()
	{
		std::ifstream read("login.txt");
		for (int i = 0; i < 2; i++)
		{
			read >> details[i];
		}
	}

	void LoginSystem::login()
	{
		ReadData();
		//Username();
		std::cout << "Enter username: ";
		std::cin >> username;
		if (details[0] == username)
		{
			std::cout << "Valid Username, please now enter your password!\n";
			Password();
			return;
		}
		std::cout << "Failure, non-valid username, please try again!\n";
		login();
	}

	void LoginSystem::Password()
	{
		std::cout << "Enter password: ";
		std::cin >> password;
		bool status = (details[1] == std::to_string(Hash(password)));
	
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