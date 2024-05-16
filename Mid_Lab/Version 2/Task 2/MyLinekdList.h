#ifndef H_MyLinkedList
#define H_MyLinkedList

#include "LinkedList.h"

class MyLinkedList : public LinkedList
{
public:
    MyLinkedList();
    void insertAtTail(int) override;
    void insertATTail(Node *);
    void insertAtHead(Node *);
    void deleteAtTail() override;
    void display() const;
    void reverseLinkedList();
    ~MyLinkedList();
};

#include "MyLinkedListImpl.cpp"

#endif