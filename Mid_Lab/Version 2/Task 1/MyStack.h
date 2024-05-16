#ifndef H_MyStack
#define H_MyStack

#include "Stack.h"
#include <iostream>

class MyStack : public Stack
{
public:
    MyStack(int = 100);
    void push(int) override;
    int pop() override;
    void display() const;
    bool isFull() const;
    bool isEmpty() const;
    char peek() const;
    void postfixEvaluation(const std::string &);
    ~MyStack();
};

#include "MyStackImpl.cpp"

#endif // H_MyStack