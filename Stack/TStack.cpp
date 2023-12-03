#include "TStack.h"

TStack::TStack() : top(0), size(1)
{
	pMem = new double[size];
}

TStack::TStack(const size_t& _size) : top(0), size(_size)
{
	pMem = new double[size];
}

TStack::TStack(const TStack& op2) : size(op2.size), top(op2.top)
{
	pMem = new double[size];
	for (int i = 0; i < size; i++) {
		pMem[i] = op2.pMem[i];
	}
}

TStack::~TStack()
{
	for (int i = 0; i < size; i++) {
		pMem[i] = 0;
	}
	size = 0;
	top = 0;
	delete[] pMem;
}

TStack& TStack::operator=(const TStack& op2)
{
	if (this != &op2) {
		if (size != op2.size) {
			delete[] pMem;
			size = op2.size;
			pMem = new double[size];
		}
		if (top != op2.top) {
			top = op2.top;
		}
		for (int i = 0; i < size; i++) {
			pMem[i] = op2.pMem[i];
		}
	}
	return *this;
}

void TStack::push(double num)
{
	pMem[top++] = num;
}

double TStack::pop()
{
	return pMem[--top];
}

bool TStack::isEmpty()
{
	return (top == 0);
}

bool TStack::isFull()
{
	return (top == size);
}
