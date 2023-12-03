#pragma once
class TStack
{
	double* pMem;
	size_t size;
	size_t top;
public:
	TStack();
	TStack(const size_t& _size);
	TStack(const TStack& op2);
	~TStack();
	TStack& operator= (const TStack& op2);
	void push(double num);
	double pop();
	bool isEmpty();
	bool isFull();
};

