#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{

	char choice;
	MyStack myStack;

	do
	{

		cout << "Press 1 to add a new item to the stack.void push(Type)\n"
				"Press 2 to remove and return the last element from the stack.Type pop()\n"
				"Press 3 to check if the stack is full.bool full()\n"
				"Press 4 to check if the stack is empty.bool empty()\n"
				"Press 5 to return the size of the stack.int size()\n"
				"Press 6 to display the stack.\n"
				"Press 7 to count even and odd numbers in the stack.\n"
				"Press 8 to count sum of even numbers present in the stack.\n"
				"Press 9 to count sum of odd numbers present in the stack.\n"
				"Press 0 to exit.\n"
				"You entered: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			int item;
			cout << "Enter the item you want to add to the stack: ";
			cin >> item;

			myStack.push(item);
			cout << "Item pushed successfully.\n";

			break;
		}
		case '2':
		{
			int removedItem = myStack.pop();
			cout << removedItem << " removed successfully from the stack.\n";

			break;
		}
		case '3':
		{
			if (myStack.full())
				cout << "Stack is full.\n";
			else
				cout << "Stack is not full.\n";
			break;
		}
		case '4':
		{
			if (myStack.empty())
				cout << "Stack is empty.\n";
			else
				cout << "Stack is not empty.\n";
			break;
		}
		case '5':
			cout << "The size of stack is " << myStack.size() << ".\n";
			break;
		case '6':
		{
			cout << "The data in stack is ";
			myStack.display();
			break;
		}
		case '7':
			myStack.count_even_and_odd();
			break;
		case '8':
			cout << "The sum of evens in stack is " << myStack.sum_of_evens() << ".\n";
			break;
		case '9':
			cout << "The sum of odds in stack is " << myStack.sum_of_odds() << ".\n";
			break;
		case '0':
			break;
		default:
			cout << "Invalid input, please try again.\n";
			break;
		}

	} while (choice != 0);

	return 0;
}