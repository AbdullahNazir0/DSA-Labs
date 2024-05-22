#ifndef H_SinglyLinkedList
#define H_SinglyLinkedList

#include "LinkedList.h"

template <typename T>
class SinglyLinkedList : public LinkedList<T>
{
public:
    SinglyLinkedList();
    void display() const;
    void search(T) const;
    void insertAtNth(T, int);
    void insertAtTail(T) override;
    void deleteAtTail() override;
    ~SinglyLinkedList();
};

#include "SinglyLinkedListImpl.cpp"

#endif