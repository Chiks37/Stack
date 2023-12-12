#include "TAriOps.h"

bool TAriOps::isBracketsCorrect()
{
	bool res = 1;
	size_t lBr = 0, rBr = 0;
	std::cout << "Left brackets         Right brackets\n";
	int errCount = 0;
	int bracketsCount = 0;
	TStack stack(line.size());
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == '(') {
			stack.push(++bracketsCount);
		}
		else if (line[i] == ')') {
			bracketsCount++;
			if (!stack.isEmpty()) {
				std::cout << stack.pop() << "                  " << bracketsCount << std::endl;
			}
			else {
				errCount++;
				std::cout << 0 << "                  " << bracketsCount << std::endl;
			}
		}
		/*if (rBr > lBr) {
			res = 0;
			errCount++;
		}
		else while (rBr > 0) {
			std::cout << lBr-- << "                  " << rBr-- << std::endl;
		}*/
	}
	while (!stack.isEmpty()) {
		errCount++;
		std::cout << stack.pop() << "                  " << 0 << std::endl;
	}
	std::cout << "Error count: " << errCount << std::endl << std::endl;
	if (errCount > 0) {
		res = 0;
	}
	return res;
}

void TAriOps::push(TStack& stack, const double& num)
{
	if (!stack.isFull()) {
		stack.push(num);
	}
	else {
		std::cout << "Stack is full. Operaion is impossible.\n";
	}
}

TAriOps::TAriOps() : line(""), errorQuantity(0)//, stack()
{
}

TAriOps::TAriOps(std::string _line) : line(_line), errorQuantity(0)//, stack()
{
}

std::string TAriOps::createPostfixForm()
{
	//std::string postfixLine;
	TStack stack(line.size());
	if (isBracketsCorrect()) {
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == '(' || line[i] == ')' || line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {

				if (stack.isEmpty() || line[i] == '(') {
					stack.push(line[i]);
				}

				else {
					double op = stack.pop();
					push(stack, op);
					if (line[i] == ')') {
						op = stack.pop();
						while (!stack.isEmpty() && op != '(') {
							postfixLine += op;
							postfixLine += ' ';
							if (!stack.isEmpty()) {
								op = stack.pop();
							}
						}
					}
					else {
						if (prioritet(line[i]) < prioritet(op)) {
							bool isOpWroten = false;
							op = stack.pop();
							do {
								postfixLine += op;
								postfixLine += ' ';
								if (!stack.isEmpty()) {
									op = stack.pop();
									if (stack.isEmpty()) {
										isOpWroten = false;
									}
									else {
										isOpWroten = true;
									}
								}
								else {
									isOpWroten = true;
								}
							} while (!stack.isEmpty() && op != '(');
							if (op == '(') {
								push(stack, op);
							}
							else if (!isOpWroten) {
								postfixLine += op;
								postfixLine += ' ';
							}
						}
						push(stack, line[i]);
					}
				}
			}
			//1+2*3*4
			else {
				postfixLine += line[i];
				postfixLine += ' ';
			}
		}
		while (!stack.isEmpty()) {
			double op = stack.pop();
			postfixLine += op;
			postfixLine += ' ';
		}
	}
	else {
		throw 1;
	}
	return postfixLine;
}

double TAriOps::solvePostfixForm(/*const std::string& postfixLine*/)
{
	TStack stack(postfixLine.size() + 1);
	double res = 0;
	for (double i = 0; postfixLine[i] != '\0'; i++) {
		if (postfixLine[i] != ' ') {
			if (!(postfixLine[i] == '+' || postfixLine[i] == '-' || postfixLine[i] == '*' || postfixLine[i] == '/')) {

				if (postfixLine[i] - '9' > 0 || '0' - postfixLine[i] > 0) {
					throw 5;
				}

				push(stack, postfixLine[i] - '0');
			}
			else {

				if (!stack.isEmpty()) {

					double op2 = stack.pop();
					if (!stack.isEmpty()) {
						double op1 = stack.pop();
						switch (postfixLine[i]) {

						case '+':
							res = op1 + op2;
							break;

						case '-':
							res = op1 - op2;
							break;

						case '*':
							res = op1 * op2;
							break;

						case '/':
							if (op2 == 0) {
								throw 3;
							}
							res = op1 / op2;
							break;
						}

						push(stack, res);
					}
					else {
						throw 2;
					}
				}
				else {
					throw 2;
				}

			}
		}
	}

	if (!stack.isEmpty()) {
		stack.pop(); //res
	}

	if (!stack.isEmpty()) {
		throw 4;
	}
	return res;
}

int TAriOps::prioritet(const double& c)
{
	int res;
	if (c == '(')
		res = 0;
	else if (c == ')')
		res = 1;
	else if (c == '+' || c == ('-'))
		res = 2;
	else if (c == '*' || c == ('/'))
		res = 3;
	else
		res = -1;
	return res;
}

