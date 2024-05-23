#include "DoublyLinkedList.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(T value)
{
    Node<T> *newNode = new Node<T>(value);
    newNode->prev = this->tail;
    newNode->next = nullptr;
    this->tail = nullptr;

    if (this->tail)
        this->tail->next = newNode;
    else
        this->head = newNode;

    this->tail = newNode;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtTail()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty list.\n";
        return;
    }

    if (this->head == this->tail)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    Node<T> *temp = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::display() const
{
    if (!this->head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
void DoublyLinkedList<T>::swapNodes()
{
    if (!this->head)
    {
        std::cout << "Cannot swap nodes of empty list.\n";
        return;
    }
    if (this->head == this->tail)
    {
        std::cout << "List has only one node, can't swap.\n";
        return;
    }

    Node<T> *firstNode = this->head;
    Node<T> *secondNode = this->tail;

    this->head->next->prev = this->tail;
    this->tail->prev->next = this->head;
    this->head = secondNode;
    this->head->prev = nullptr;
    this->head->next = firstNode->next;
    this->tail = firstNode;
    this->tail->next = nullptr;
    this->tail->prev = secondNode->prev;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    if (!this->head)
        return;

    Node<T> *temp = this->head;
    while (temp)
    {
        Node<T> *next = temp->next;
        delete temp;
        temp = next;
    }
}