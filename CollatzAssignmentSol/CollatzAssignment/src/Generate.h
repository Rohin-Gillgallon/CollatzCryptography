#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class Generate : public StrengthAnalysis
{
private:
	//void swap(char& a, char& b);
	//void randomize(char arr[], int n);
	void write(std::string& word);
	//std::string FirstGroup();
	//std::string SecondGroup();
public:
	void Gen1();
	void Gen2();
	Generate() {};
	~Generate() {};

};