#pragma once
class TStack
{
	char* pMem;
	size_t size;
	size_t top;
public:
	TStack();
	TStack(const size_t& _size);
	TStack(const TStack& op2);
	~TStack();
	TStack& operator= (const TStack& op2);
	void push(char num);
	char pop();
	bool isEmpty();
	bool isFull();
};

