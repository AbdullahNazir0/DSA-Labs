#ifndef H_MyLinkedList
#define H_MyLinkedList

#include "LinkedList.h"

class MyLinkedList : public LinkedList
{
public:
    MyLinkedList();
    MyLinkedList(const MyLinkedList &obj);
    void display() const;
    void insertAtTail(int) override;
    void deleteAtTail() override;
    ~MyLinkedList();
    void sum();
    void removeOddValues();
};

#endif