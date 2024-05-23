#include <iostream>
#include "DoublyCircularLinkedList.h"

using namespace std;

int main()
{

    DoublyCircularLinkedList<int> dll;
    char choice;

    while (1)
    {
        cout << "Press 1 to add a new element to the tail of linkedlist.\n"
                "Press 2 to delete the element from tail end of linkedlist.\n"
                "Press 3 to display the LinkedList.\n"
                "Press 4 to swap Head and Tail nodes in Doubly LinkedList.\n"
                "Press 5 to check palindrome in Doubly Circular LinkedList.\n"
                "Press 0 to exit.\n"
                "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            int value;
            cout << "Enter the value to be added: ";
            cin >> value;
            dll.insertAtTail(value);
            break;
        }
        case '2':
            dll.deleteAtTail();
            break;
        case '3':
            dll.display();
            break;
        case '4':
            dll.swapNodes();
            break;
        case '5':
            dll.checkPalindrome();
            break;
        case '0':
            return 0;
        }
    }
}