#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <any>

class Generate : public StrengthAnalysis
{
private:
	void write(std::string& word);
	void Gen1();
	void Gen2();
public:
	void System();
	Generate() {};
	~Generate() {};
};