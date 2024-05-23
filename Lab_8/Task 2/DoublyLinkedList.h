#ifndef H_DoublyLinkedList
#define H_DoublyLinkedList

#include "LinkedList.h"

template <typename T>
class DoublyLinkedList : public LinkedList<T>
{
public:
    DoublyLinkedList();
    void insertAtTail(T) override;
    void deleteAtTail() override;
    void display() const;
    void swapNodes(); // swap head and tail nodes
    ~DoublyLinkedList();
};

#include "DoublyLinkedListImpl.cpp"

#endif