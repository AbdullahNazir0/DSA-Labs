#ifndef H_LinkedList
#define H_LinkedList

#include "Node.h"

template <typename T>
class LinkedList
{
public:
    LinkedList() {}
    virtual void insertAtTail(T) = 0;
    virtual void deleteAtTail() = 0;

protected:
    Node<T> *head;
    Node<T> *tail;
};

#endif