#include "MyStack.h"

#include <iostream>

MyStack::MyStack(int size)
{
    stackTop = -1;
    maxSize = size;
    stackArray = new int[size];
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
bool MyStack::isPresent(int value)
{
    if (empty())
        return false;

    for (int i = 0; i < stackTop + 1; i++)
    {
        if (stackArray[i] == value)
            return true;
    }
    return false;
}
void MyStack::display()
{
    if (empty())
    {
        std::cout << "Stack is empty\n";
        return;
    }

    std::cout << "Stack Data: ";
    for (int i = 0; i < stackTop + 1; i++)
        std::cout << stackArray[i] << " ";
    std::cout << "\n";
}
void MyStack::push(int value)
{
    if (full())
    {
        std::cout << "Cannot push in full stack (stack overflow).\n";
        return;
    }
    stackArray[++stackTop] = value;
}
int MyStack::pop()
{
    if (empty())
    {
        std::cout << "Cannot pop from empty stack (stack underflow).\n";
        return -1;
    }
    return (stackArray[stackTop--]);
}
void MyStack::reverseStack(MyStack &inputStack)
{
    if (inputStack.empty())
    {
        std::cout << "Empty stack cannot be reversed.\n";
        return;
    }
    int *temp = new int[inputStack.maxSize];
    int count = 0;
    while (!inputStack.empty())
        temp[count++] = inputStack.pop();
    delete[] inputStack.stackArray;
    inputStack.stackArray = temp;
    inputStack.stackTop = count - 1;
}
void MyStack::RemoveDuplicates(MyStack &inputStack)
{
    if (inputStack.empty())
    {
        std::cout << "Duplicates cannot be removed from empty stack.\n";
        return;
    }
    int poppedValue;
    MyStack temp = MyStack(inputStack.maxSize);
    while (!inputStack.empty())
    {
        poppedValue = inputStack.pop();
        if (!temp.isPresent(poppedValue))
            temp.push(poppedValue);
    }
    while (!temp.empty())
        inputStack.push(temp.pop());
}
MyStack::~MyStack()
{
    if (stackArray)
        delete[] stackArray;
}