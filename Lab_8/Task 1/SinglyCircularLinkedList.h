#ifndef H_SinglyCircularLinkedList
#define H_SinglyCircularLinkedList

#include "SinglyLinkedList.h"

template <typename T>
class SinglyCircularLinkedList : public SinglyLinkedList<T>
{
public:
    SinglyCircularLinkedList();
    void insertAtHead(T);
    void deleteAtHead();
    ~SinglyCircularLinkedList();
};

#include "SinglyCircularLinkedListImpl.cpp"

#endif