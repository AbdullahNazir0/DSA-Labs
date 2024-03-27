#ifndef H_MyStack
#define H_MyStack

#include "Stack.h"

class MyStack : public Stack
{
public:
	MyStack();
	MyStack(const MyStack &other);
	void display() const;
	bool empty();
	bool full();
	int size();
	int top();
	void push(int) override;
	int pop() override;
	void count_even_and_odd() const;
	int sum_of_evens() const;
	int sum_of_odds() const;
	~MyStack();
};

#endif