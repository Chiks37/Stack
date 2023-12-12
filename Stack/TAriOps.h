#pragma once
#include <iostream>
#include "TStack.h"
#include <string>
class TAriOps
{
	std::string line;
	std::string postfixLine;
	size_t errorQuantity;
	//TStack stack;
	bool isBracketsCorrect();
	void push(TStack& stack, const double& num);
public:
	TAriOps();
	TAriOps(std::string _line);
	std::string createPostfixForm();
	double solvePostfixForm(/*const std::string& postfixLine*/);
	int prioritet(const double& c);
};

