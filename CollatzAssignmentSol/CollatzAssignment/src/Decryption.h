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
public:
	int DecryptCount(std::string& passwords);
	bool decrypt(std::string& example, std::string& group, int groupno);
	DecryptPasswords() {};
	~DecryptPasswords() {};
};