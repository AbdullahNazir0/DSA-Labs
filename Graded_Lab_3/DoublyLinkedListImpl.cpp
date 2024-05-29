#include "DoublyLinkedList.h"

#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::display() const
{
    if(! this->head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node<T> *temp = this->head;
    while(temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(const T &value) 
{
    Node<T> *newNode = new Node<T>(value);

    if(!this->head)
    {
        this->head = newNode;
        this->tail = newNode; 
        return;
    }

    this->tail->next = newNode;
    newNode->prev = this->tail;
    this->tail = newNode;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtTail() 
{
    if(!this->head)
    {
        std::cout << "Cannot delete from empty linked list.\n";
        return;
    }

    if(this->head == this->tail) // if only one node.
    {
        this->head = nullptr;
        delete this->tail;
        this->tail = nullptr;
    }

    Node<T> *nodeToDelete = this->tail->prev;
    this->tail = this->tail->prev;
    delete nodeToDelete;
}

template <typename T>
void DoublyLinkedList<T>::RotateAndDelete(int n, int m) 
{
    if(n > m)
    {
        std::cout << "Invalid positions.\n";
        return;
    }
    if(!this->head)
    {
        std::cout << "Cannot delete empty list.\n";
        return;
    }

    int count = 0;
    Node<T> *temp = this->head;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    if(count < m || count < n)
    {
        std::cout << "Invalid positions.\n";
        return;
    }
    
    Node<T> *curr2 = this->head;
    for(int i = 0; i < n - 1; i++)
        curr2 = curr2->next;

    Node<T> *curr = this->head;
    for(int i = 0; i < m - 1; i++)
        curr = curr->next;

    curr2->prev->next = curr2->next;
    curr2->next->prev = curr2->prev;

    curr->prev->next = curr2;
    curr2->prev = curr->prev;
    curr->next->prev = curr2;
    curr2->next = curr->next;
    
    delete curr;    
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{}
