#ifndef H_DoublyLinkedList
#define H_DoublyLinkedList

#include "LinkedList.h"

template <typename T>
class DoublyLinkedList : public LinkedList<T>
{
public:
    DoublyLinkedList();
    void display() const;
    void insertAtTail(const T &) override;
    void deleteAtTail() override;
    void RotateAndDelete(int , int);    // Takes two int parameters and rotate first int to second and then delete second.
     ~DoublyLinkedList();
};

#include "DoublyLinkedListImpl.cpp"

#endif