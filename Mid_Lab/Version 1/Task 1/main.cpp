#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{

    MyStack<char> stack;
    string input;

    cout << "Input: ";
    cin >> input;

    cout << "Output: ";
    stack.checkParenthesis(input);

    return 0;
}