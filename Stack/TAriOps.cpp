#include "TAriOps.h"

bool TAriOps::isBracketsCorrect()
{
	bool res = 1;
	size_t lBr = 0, rBr = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == '(') {
			lBr++;
		}
		else if (line[i] == ')') {
			rBr++;
		}
		if (rBr > lBr) {
			res = 0;
			break;
		}
	}
	return res;
}

void TAriOps::push(TStack& stack, const int& num)
{
	if (!stack.isFull()) {
		stack.push(num);
	}
	else {
		std::cout << "Stack is full. Operaion is inpossible.\n";
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
	std::string postfixLine;
	TStack stack(line.size());
	if (isBracketsCorrect()) {
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == '(' || line[i] == ')' || line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {

				if (stack.isEmpty() || line[i] == '(') {
					stack.push(line[i]);
				}

				else {
					char op = stack.pop();
					push(stack, op);
					if (prioritet(line[i]) > prioritet(op)) {
						push(stack, line[i]);
					}

					else {
						op = stack.pop();
						if (op == '(')
							push(stack, op);
						else do {
							postfixLine += op;
							if (!stack.isEmpty()) {
								op = stack.pop();
							}
						} while (!stack.isEmpty() && op != '(');
						/*while (!stack.isEmpty() && op != '(') {
							postfixLine += op;
							op = stack.pop();
						}*/
						if (line[i] != ')') {
							if (op == '(')
								push(stack, op);
							push(stack, line[i]);
						}
					}
				}
			}
			else {
				postfixLine += line[i];
			}
		}
		while (!stack.isEmpty()) {
			char op = stack.pop();
			postfixLine += op;
		}
	}
	else {
		std::cout << "Bracket count is uncorrect";
	}
	return postfixLine;
}

int TAriOps::solvePostfixForm(const std::string& postfixLine)
{
	TStack stack(postfixLine.size());
	int res = 0;
	for (int i = 0; postfixLine[i] != '\0'; i++) {
		if (!( postfixLine[i] == '+' || postfixLine[i] == '-' || postfixLine[i] == '*' || postfixLine[i] == '/')) {
			push(stack, postfixLine[i]);
		}
		else {
			if (!stack.isEmpty()) {
				int op2 = stack.pop();
				if (!stack.isEmpty()) {
					int op1 = stack.pop();
					switch (postfixLine[i]) {
					case '+':
						res += op1 + op2;
						break;
					case '-':
						res += op1 - op2;
						break;
					case '*':
						res += op1 * op2;
						break;
					case '/':
						res += op1 / op2;
						break;
					}

				}
			}

		}
	}
	return res;
}

int TAriOps::prioritet(const char& c)
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

