#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>

class DecryptPasswords : public StrengthAnalysis
{
private:
	bool decrypt(std::string& example, std::string& group, int groupno);
	void DecryptCount();
	std::string FirstGroup();
public:
	void System();
	DecryptPasswords() {};
	~DecryptPasswords() {};
};