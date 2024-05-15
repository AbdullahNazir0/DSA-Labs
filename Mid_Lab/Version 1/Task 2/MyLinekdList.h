#ifndef H_MyLinkedList
#define H_MyLinkedList

#include "LinkedList.h"

template <typename T>
class MyLinkedList : public LinkedList<T>
{
public:
    MyLinkedList();
    void insertAtTail(const T &) override;
    void deleteAtTail() override;
    void display() const;
    void moveNthToHead(int);
    ~MyLinkedList();
};

#include "MyLinkedListImpl.cpp"

#endif