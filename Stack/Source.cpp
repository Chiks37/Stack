#include <iostream>
#include "TStack.h"
#include "TAriOps.h"


//Errors list: 
//1 - brakets
//2 - not enough operands
//3 - divide by zero
//4 - not enough operations
void startTest(std::string str) {

	TAriOps obj(str);
	std::string postLine;
	double result = 0;

	try {
		postLine = obj.createPostfixForm();
		result = obj.solvePostfixForm();
	}

	catch (int& e) {
		switch (e) {
		case 1:
			std::cout << "Error #1: brackets are incorrect.\n";
			break;
		case 2:
			std::cout << "Error #2: not enough operands.\n";
			break;
		case 3:
			std::cout << "Error #3: divide by zero.\n";
			break;
		case 4:
			std::cout << "Error #4: Not enough operations.\n";
			break;
		case 5:
			std::cout << "Error #5: wrong operands.\n";
			break;
		}

	}
	std::cout << "Infix line:   " << str << "\nPostfix line: " << postLine << "\nSolution:     " << result << "\n\n";
}

void main() {
	/*char a = 0;	
	for (int i = 0; i < 256; i++) {
		std::cout << i << ": " << a++ << '\n';
	}*/
	while (true) {

		std::cout << "Enter a line >> ";
		std::string str;
		std::cin >> str;
		std::cout << std::endl;

		startTest(str);
	}

}