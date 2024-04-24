#include <iostream>
#include "MyLinkedList.h"

using namespace std;

void displayMenu()
{
    cout << "Menu:\n";
    cout << "1. Add a new element to the tail of linked list.\n";
    cout << "2. Delete the element from the tail end of linked list.\n";
    cout << "3. Display the linked list.\n";
    cout << "4. Calculate sum of all elements in linked list.\n";
    cout << "5. Delete all nodes having an odd value from linked list.\n";
    cout << "0. Exit.\n";
}

int main()
{
    MyLinkedList list;
    int choice, value;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insertAtTail(value);
            break;
        case 2:
            list.deleteAtTail();
            break;
        case 3:
            cout << "Linked List: ";
            list.display();
            cout << endl;
            break;
        case 4:
            list.sum();
            break;
        case 5:
            list.removeOddValues();
            cout << "Nodes with odd values removed.\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}