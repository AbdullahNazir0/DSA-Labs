#include <iostream>
#include "MyLinekdList.h"

using namespace std;

int main()
{

    MyLinkedList list;

    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    list.display();
    list.reverseLinkedList();

    list.display();

    return 0;
}