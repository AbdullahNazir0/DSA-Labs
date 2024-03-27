#include "MyStack.h"
#include <iostream>

using namespace std;

MyStack::MyStack()
{
	stackTop = -1;
	maxSize = 100;
	stackArray = new int[maxSize];
}

MyStack::MyStack(const MyStack &other)
{
	stackTop = other.stackTop;
	maxSize = other.maxSize;
	stackArray = new int[maxSize];
	for (int i = 0; i < stackTop + 1; i++)
		stackArray[i] = other.stackArray[i];
}

void MyStack::display() const
{
	for (int i = 0; i < stackTop + 1; i++)
		cout << stackArray[i] << " ";
	cout << endl;
}

bool MyStack::empty()
{
	return (stackTop == -1);
}

bool MyStack::full()
{
	return (stackTop == maxSize - 1);
}

int MyStack::size()
{
	return (maxSize);
}

int MyStack::top()
{
	return (stackTop);
}

void MyStack::push(int element)
{
	if (full())
		return;

	stackArray[++stackTop] = element;
}

int MyStack::pop()
{
	if (empty())
		return -1;

	int temp = stackArray[stackTop--];
	return temp;
}

void MyStack::count_even_and_odd() const
{
	int even = 0, odd = 0;

	for (int i = 0; i < stackTop + 1; i++)
	{
		if (stackArray[i] % 2 == 0)
			even++;
		else
			odd++;
	}

	cout << "Total evens in stack are: " << even << ".\n";
	cout << "Total odds in stack are: " << odd << ".\n";
}

int MyStack::sum_of_evens() const
{
	int sum = 0;

	for (int i = 0; i < stackTop + 1; i++)
	{
		if (stackArray[i] % 2 == 0)
			sum += stackArray[i];
	}

	return sum;
}

int MyStack::sum_of_odds() const
{
	int sum = 0;

	for (int i = 0; i < stackTop + 1; i++)
	{
		if (stackArray[i] % 2 != 0)
			sum += stackArray[i];
	}

	return sum;
}

MyStack::~MyStack()
{
	if (stackArray)
		delete[] stackArray;
}