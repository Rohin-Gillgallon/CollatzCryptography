#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class StrengthAnalysis : public Collatz
{
protected:
	void swap(char& a, char& b);
	void randomize(char arr[], int n);
	template <typename T>
	T random(T low, T high)
	{
		srand((int)std::time(0) * rand() * (int)std::time(NULL));
		T randNum = (rand() % (high + 1 - low)) + low;
		return randNum;
	};
	virtual std::string FirstGroup();
	std::string SecondGroup();
public:
	virtual void System();
	StrengthAnalysis() {};
	virtual ~StrengthAnalysis() {};
};