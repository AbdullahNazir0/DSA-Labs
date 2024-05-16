#include "MyLinekdList.h"
#include <iostream>
#include "MyQueue.h"

MyLinkedList::MyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void MyLinkedList::insertAtTail(int value)
{
    Node *toAdd = new Node(value);

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

void MyLinkedList::insertATTail(Node *value)
{
    if (!value)
    {
        std::cout << "Can't insert empty node.\n";
        return;
    }

    if (!this->head)
    {
        this->head = value;
        this->tail = value;
    }
    else
    {
        this->tail->next = value;
        this->tail = value;
    }
}

void MyLinkedList::insertAtHead(Node *value)
{
    if (!value)
    {
        std::cout << "Can't insert empty node.\n";
        return;
    }

    value->next = this->head;
    this->head = value;
}

void MyLinkedList::deleteAtTail()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty list.\n";
        return;
    }

    Node *temp = this->head;
    while (temp->next != this->tail)
        temp = temp->next;
    delete this->tail;
    this->tail = temp;
}

void MyLinkedList::display() const
{
    if (!this->head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node *temp = this->head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void MyLinkedList::reverseLinkedList()
{
    if (this->head == nullptr || this->head->next == nullptr)
        return;

    MyQueue queue;
    Node *temp = this->head;
    while (temp)
    {
        queue.enqueue(temp);
        temp = temp->next;
    }

    this->head = nullptr;
    while (!queue.isEmpty())
        insertAtHead(queue.dequeue());
}

MyLinkedList::~MyLinkedList()
{
    Node *temp = this->head;
    while (temp)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
}
