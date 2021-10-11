#pragma once

class LoginSystem
{
private:
	int passwordcount = 0;
	void reg();
	bool Authorise();
	void login();

public:
	LoginSystem() {};
	~LoginSystem() {};
	void system();
};

