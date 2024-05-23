#ifndef H_DoublyCircularLinkedList
#define H_DoublyCircularLinkedList

#include "DoublyLinkedList.h"

template <typename T>
class DoublyCircularLinkedList : public DoublyLinkedList<T>
{
public:
    DoublyCircularLinkedList();
    void checkPalindrome();
    ~DoublyCircularLinkedList();
};

#include "DoublyCircularLinkedListImpl.cpp"

#endif