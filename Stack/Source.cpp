#include <iostream>
#include "TStack.h"
#include "TAriOps.h"

void main() {
	//TStack stack(3);
	//stack.push(1);
	//std::cout << stack.pop();
	std::string str1 = "2+3*3";
	TAriOps a(str1);
	std::string str2 = "((2+1)/(9-3)+2)*3-7";
	TAriOps b(str2);
	std::string str3 = "((2+1)/(9-3)+2)+5-2-2*(5-4)+7";
	TAriOps c(str3);
	std::cout << "Infix line:   " << str1 << "\nPostfix line: " << a.createPostfixForm() << "\nSolution:    " << a.solvePostfixForm(str1)
		<< "\n\nInfix line:   " << str2 << "\nPostfix line: " << b.createPostfixForm() << "\nSolution:    " << b.solvePostfixForm(str2)
		<< "\n\nInfix line:   " << str3 << "\nPostfix line: " << c.createPostfixForm() << "\nSolution:    " << c.solvePostfixForm(str3) << std::endl;
}