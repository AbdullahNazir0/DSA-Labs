#include "MyStack.h"

template <typename T>
MyStack<T>::MyStack(int size)
{
    this->maxSize = size;
    this->stackTop = -1;
    this->stackArray = new T[size];
}

template <typename T>
void MyStack<T>::push(const T &value)
{
    if (isFull())
    {
        std::cout << "Can't push, stack is full. (Stack overflown)\n";
        return;
    }

    this->stackArray[++this->stackTop] = value;
}

template <typename T>
T MyStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Can't pop, stack is empty. (Stack underflown)\n";
        return (' ');
    }

    return (this->stackArray[this->stackTop--]);
}

template <typename T>
void MyStack<T>::display() const
{
    if (isEmpty)
    {
        std::cout << "Stack is empty.\n";
        return;
    }

    for (int i = 0; i < this->stackTop + 1; i++)
        std::cout << this->stackArray[i] << " ";
    std::cout << "\n";
}

template <typename T>
bool MyStack<T>::isEmpty() const
{
    return (this->stackTop == -1);
}

template <typename T>
bool MyStack<T>::isFull() const
{
    return (this->stackTop == this->maxSize - 1);
}

template <typename T>
char MyStack<T>::peek() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty, can't peek.\n";
        return (' ');
    }
    return (this->stackArray[this->stackTop]);
}

template <typename T>
void MyStack<T>::checkParenthesis(const std::string &expression)
{
    int initialTop = this->stackTop;
    for (char scanner : expression)
    {
        if (scanner == '(' || scanner == '[' || scanner == '{')
            push(scanner);
        else if (scanner == ')' || scanner == ']' || scanner == '}')
        {
            char toCheck = peek();
            if (scanner == ')' && toCheck == '(' ||
                scanner == ']' && toCheck == '[' ||
                scanner == '}' && toCheck == '{')
                pop();
            else
            {
                std::cout << "Unbalanced\n";
                return;
            }
        }
    }
    if (this->stackTop == initialTop)
        std::cout << "Balanced\n";
    else
        std::cout << "Unbalanced\n";
}

template <typename T>
MyStack<T>::~MyStack()
{
    if (this->stackArray)
        delete this->stackArray;
}