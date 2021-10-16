#pragma once
#include <iostream>
#include <sstream>
#include <functional>
//#include <algorithm>
#include <vector>

class Collatz
{
public:
	Collatz();
	virtual ~Collatz();
	friend std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)>& toString);
};