#include "MyLinekdList.h"
#include <iostream>

template <typename T>
MyLinkedList<T>::MyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
void MyLinkedList<T>::insertAtTail(const T &value)
{
    Node<T> *toAdd = new Node<T>(value);

    if (!this->head)
    {
        this->head = toAdd;
        this->tail = toAdd;
    }
    else
    {
        this->tail->next = toAdd;
        this->tail = toAdd;
    }
}

template <typename T>
void MyLinkedList<T>::deleteAtTail()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty list.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next != this->tail)
        temp = temp->next;
    delete this->tail;
    this->tail = temp;
}

template <typename T>
void MyLinkedList<T>::display() const
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
void MyLinkedList<T>::moveNthToHead(int n)
{
    if (!this->head)
    {
        std::cout << "List is empty, can't move.\n";
        return;
    }

    Node<T> *temp = this->head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    if (n <= 0 || n > count)
    {
        std::cout << "Invalid position, can't move\n";
        return;
    }

    temp = this->head;
    Node<T> *prev = nullptr;
    for (int i = 1; i < n; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == this->tail)
    {
        this->tail = prev;
        this->tail->next = nullptr;
        temp->next = this->head;
        this->head = temp;
    }
    else
    {
        prev->next = temp->next;
        temp->next = this->head;
        this->head = temp;
    }
}

template <typename T>
MyLinkedList<T>::~MyLinkedList()
{
    Node<T> *temp = this->head;
    while (temp)
    {
        Node<T> *next = temp->next;
        delete temp;
        temp = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
}
