#ifndef H_LinkedList
#define H_LinkedList

#include "Node.h"

class LinkedList
{
public:
    LinkedList() {}
    virtual void insertAtTail(int) = 0;
    virtual void deleteAtTail() = 0;
    ~LinkedList() {}

protected:
    Node *head;
    Node *tail;
};

#endif // H_LinkedList