#pragma once
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <vector>

class LoginSystem : public Collatz
{
private:
	std::string username, password, un, pw;
	std::string details[2];
	std::hash<std::string> Hash;
	int passwordcount = 0;
	void reg();
	//bool Authorise();
	void login();
	void ReadData();
	//void Username();
	void Password();

public:
	LoginSystem() {};
	~LoginSystem() {};
	void system();
	friend std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString);
};

