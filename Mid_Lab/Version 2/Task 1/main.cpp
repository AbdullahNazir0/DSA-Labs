#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{

    MyStack stack;
    string input;

    cout << "Input: ";
    cin >> input;

    cout << "Output: ";
    stack.postfixEvaluation(input);

    return 0;
}