#include "MyStack.h"

bool isOperator(char value);
bool isNumber(char value);

MyStack::MyStack(int size)
{
    this->maxSize = size;
    this->stackTop = -1;
    this->stackArray = new int[size];
}

void MyStack::push(int value)
{
    if (isFull())
    {
        std::cout << "Can't push, stack is full. (Stack overflown)\n";
        return;
    }

    this->stackArray[++this->stackTop] = value;
}

int MyStack::pop()
{
    if (isEmpty())
    {
        std::cout << "Can't pop, stack is empty. (Stack underflown)\n";
        return (-1);
    }

    return (this->stackArray[this->stackTop--]);
}

void MyStack::display() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty.\n";
        return;
    }

    for (int i = 0; i < this->stackTop + 1; i++)
        std::cout << this->stackArray[i] << " ";
    std::cout << "\n";
}

bool MyStack::isEmpty() const
{
    return (this->stackTop == -1);
}

bool MyStack::isFull() const
{
    return (this->stackTop == this->maxSize - 1);
}

char MyStack::peek() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty, can't peek.\n";
        return (' ');
    }
    return (this->stackArray[this->stackTop]);
}

void MyStack::postfixEvaluation(const std::string &expression)
{
    int result;
    for (int scanner = 0; scanner < expression.length(); scanner++)
    {
        if (isNumber(expression[scanner]))
        {
            int numericValue = expression[scanner] - '0';
            push(numericValue);
        }
        else if (isOperator(expression[scanner]))
        {
            int value1 = pop();
            int value2 = pop();
            switch (expression[scanner])
            {
            case '+':
                result = value2 + value1;
                break;
            case '-':
                result = value2 - value1;
                break;
            case '*':
                result = value2 * value1;
                break;
            case '/':
                result = value2 / value1;
                break;
            case '%':
                result = value2 % value1;
                break;
            }
            push(result);
        }
    }
    std::cout << result << "\n";
}

MyStack::~MyStack()
{
    if (this->stackArray)
        delete this->stackArray;
}

bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%');
}
bool isNumber(char value)
{
    return (value >= 48 && value <= 57);
}