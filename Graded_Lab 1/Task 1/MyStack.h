#ifndef H_MyStack
#define H_MyStack

#include "Stack.h"

class MyStack : public Stack
{
public:
    MyStack(int = 100);
    bool empty();
    bool full();
    int size();
    int top();
    bool isPresent(int);
    void display();
    void push(int) override;
    int pop() override;
    void reverseStack(MyStack &);
    void RemoveDuplicates(MyStack &);
    ~MyStack();
};

#include "MyStackImpl.cpp"

#endif