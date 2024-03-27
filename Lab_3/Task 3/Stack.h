#ifndef H_Stack
#define H_Stack

class Stack
{
public:
	virtual void push(int) = 0;
	virtual int pop() = 0;

protected:
	int *stackArray;
	int maxSize;
	int stackTop;
};

#endif