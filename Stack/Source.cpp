#include <iostream>
#include "TStack.h"
#include "TAriOps.h"

void main() {
	//TStack stack(3);
	//stack.push(1);
	//std::cout << stack.pop();
	std::string str1 = "2+3*3";
	TAriOps a(str1);
	std::string aPostLine = a.createPostfixForm();
	double aResult = a.solvePostfixForm();
	std::cout << "Infix line:   " << str1 << "\nPostfix line: " << aPostLine << "\nSolution:    " << aResult;

	std::string str2 = "((2+1)/(9-3)+2)*3-7";
	TAriOps b(str2);
	std::string bPostLine = b.createPostfixForm();
	double bResult = b.solvePostfixForm();
	std::cout << "\n\nInfix line:   " << str2 << "\nPostfix line: " << bPostLine << "\nSolution:    " << bResult;

	std::string str3 = "((2+1)/(9-3)+2)+5-2-2*(5-4)+7";
	TAriOps c(str3);
	std::string cPostLine = c.createPostfixForm();
	double cResult = c.solvePostfixForm();
	std::cout << "\n\nInfix line:   " << str3 << "\nPostfix line: " << cPostLine << "\nSolution:    " << cResult;

	std::string str4 = "1+2*(3-2)-4";
	TAriOps d(str4);
	std::string dPostLine = d.createPostfixForm();
	double dResult = d.solvePostfixForm();
	std::cout << "\n\nInfix line:   " << str4 << "\nPostfix line: " << dPostLine << "\nSolution:    " << dResult << std::endl;
}