#pragma once
#include <iostream>
#include <sstream>
#include <functional>
#include <vector>

class Collatz
{
public:
	Collatz();
	virtual ~Collatz();
	friend std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString);
protected:
	void checkfile(std::string filname);
};