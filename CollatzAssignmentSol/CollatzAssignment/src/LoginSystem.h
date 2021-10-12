#pragma once

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
};

