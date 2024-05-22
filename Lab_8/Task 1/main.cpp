#include <iostream>
#include "SinglyCircularLinkedList.h"
using namespace std;

int main()
{

    SinglyCircularLinkedList<int> sll;
    char choice;
    while (1)
    {

        cout << "Press 1 to add a new element to the tail of linkedlist.\n"
                "Press 2 to delete the element from tail end of linkedlist.\n"
                "Press 3 to display the LinkedList.\n"
                "Press 4 to search and display the position of a given element in Singly LinkedList.\n"
                "Press 5 to insert new node at the Nth position in the Singly LinkedList.\n"
                "Press 6 to insert new node at the head in Singly Circular LinkedList.\n"
                "Press 7 to delete the head node in Singly Circular LinkedList.\n"
                "Press 0 to exit.\n"
                "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            int value;
            cout << "Enter the value you want to insert at tail.\n";
            cin >> value;
            sll.insertAtTail(value);
            break;
        }
        case '2':
        {
            cout << "Deleting at tail\n";
            sll.deleteAtTail();
            break;
        }
        case '3':
        {
            cout << "Displaying LinkedList\n";
            sll.display();
            break;
        }
        case '4':
        {
            int value;
            cout << "Enter the element whose position you want to search\n";
            cin >> value;
            sll.search(value);
            break;
        }
        case '5':
        {
            int value, position;
            cout << "Enter the element you want to insert at Nth position\n";
            cin >> value;
            cout << "Enter the position\n";
            cin >> position;
            sll.insertAtNth(value, position);
            break;
        }
        case '6':
        {
            int value;
            cout << "Enter the value you want to insert at head\n";
            cin >> value;
            sll.insertAtHead(value);
        }
        break;
        case '7':
        {
            cout << "Deleting at head\n";
            sll.deleteAtHead();
            break;
        }
        case '0':
        {
            cout << "Exiting\n";
            return 0;
        }
        }
    }
}

/*
1.	Press 1 to add a new element to the tail of linkedlist. void insertAtTail(int)
2.	Press 2 to delete the element from tail end of linkedlist. void deleteAtTail()
3.	Press 3 to display the LinkedList.
4.	Press 4 to search and display the position of a given element in Singly LinkedList.
5.	Press 5 to insert new node at the Nth position in the Singly LinkedList.
6.	Press 6 to insert new node at the head in Singly Circular LinkedList. void insertAtHead(int)
7.	Press 7 to delete the head node in Singly Circular LinkedList. void deleteAtHead(int)
8.	Press 0 to exit.
*/