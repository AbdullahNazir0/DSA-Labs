#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{
    MyStack stack = MyStack(10);
    stack.display();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(1);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.display();
    stack.reverseStack(stack);
    stack.display();
    stack.RemoveDuplicates(stack);
    stack.display();

    return 0;
}