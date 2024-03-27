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
    ~MyStack();
};

#endif