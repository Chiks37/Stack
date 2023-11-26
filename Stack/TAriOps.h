#pragma once
#include <iostream>
#include "TStack.h"
#include <string>
class TAriOps
{
	std::string line;
	size_t errorQuantity;
	//TStack stack;
	bool isBracketsCorrect();
	void push(TStack& stack, const int& num);
public:
	TAriOps();
	TAriOps(std::string _line);
	std::string createPostfixForm();
	int solvePostfixForm(const std::string& postfixLine);
	int prioritet(const char& c);
};

