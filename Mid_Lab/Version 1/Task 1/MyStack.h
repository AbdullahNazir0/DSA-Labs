#ifndef H_MyStack
#define H_MyStack

#include "Stack.h"
#include <iostream>

template <typename T>
class MyStack : public Stack<T>
{
public:
    MyStack(int = 100);
    void push(const T &) override;
    T pop() override;
    void display() const;
    bool isFull() const;
    bool isEmpty() const;
    char peek() const;
    void checkParenthesis(const std::string &);
    ~MyStack();
};

#include "MyStackImpl.cpp"

#endif // H_MyStack