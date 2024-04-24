#include "MyLinkedList.h"

#include <iostream>

MyLinkedList::MyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}
MyLinkedList::MyLinkedList(const MyLinkedList &obj)
{
    head = obj.head;
    tail = obj.tail;
}
void MyLinkedList::display() const
{
    if (!head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << "\n";
}
void MyLinkedList::insertAtTail(int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void MyLinkedList::deleteAtTail()
{
    if (!head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    tail = temp;
    temp->next = nullptr;
}
MyLinkedList::~MyLinkedList()
{
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}
void MyLinkedList::sum()
{
    if (!head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    int sum = 0;
    Node *temp = head;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next;
    }

    std::cout << "Sum of elements: " << sum << "\n";
}
void MyLinkedList::removeOddValues()
{
    if (!head)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node *prev = nullptr;
    Node *temp = head;
    while (temp)
    {
        if (temp->data % 2 != 0)
        {
            if (temp == head)
            {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}