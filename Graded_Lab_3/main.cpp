#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{

    DoublyLinkedList<int> dll;

    dll.insertAtTail(2);
    dll.insertAtTail(6);
    dll.insertAtTail(1);
    dll.insertAtTail(7);
    dll.insertAtTail(3);
    dll.insertAtTail(8);
    dll.insertAtTail(5);
    dll.insertAtTail(0);

    dll.display();

    dll.RotateAndDelete(3, 7);

    dll.display();

    return 0;
}