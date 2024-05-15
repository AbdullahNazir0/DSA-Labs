#include <iostream>
#include "MyLinekdList.h"

using namespace std;

int main()
{

    MyLinkedList<int> list;

    list.insertAtTail(5);
    list.insertAtTail(11);
    list.insertAtTail(34);
    list.insertAtTail(67);
    list.insertAtTail(43);
    list.insertAtTail(55);

    list.display();

    list.moveNthToHead(3);

    list.display();

    return 0;
}