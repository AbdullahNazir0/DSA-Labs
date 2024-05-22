#include "SinglyLinkedList.h"
#include <iostream>

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}
template <typename T>
void SinglyLinkedList<T>::display() const
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
void SinglyLinkedList<T>::search(T value) const
{
    if (!this->head)
        return;

    std::cout << "Element '" << value << "' is at position: ";
    int count = 0;
    Node<T> *temp = this->head;
    while (temp)
    {
        if (temp->data == value)
            std::cout << count << " ";
        count++;
        temp = temp->next;
    }
    std::cout << "\n";
}
template <typename T>
void SinglyLinkedList<T>::insertAtNth(T value, int index)
{
    if (!this->head)
    {
        std::cout << "List is empty. (Not inserted)\n";
        return;
    }
    if (index < 0)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    if (index == 0)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = this->head;
        this->head = newNode;
        return;
    }
    int count = 0;
    Node<T> *temp = this->head;
    while (temp)
    {
        if (count == index - 1)
        {
            Node<T> *newNode = new Node<T>(value);
            if (temp == this->tail)
            {
                temp->next = newNode;
                this->tail = newNode;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            return;
        }
        count++;
        temp = temp->next;
    }
    std::cout << "Invalid index.\n";
}
template <typename T>
void SinglyLinkedList<T>::insertAtTail(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!this->head)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
}
template <typename T>
void SinglyLinkedList<T>::deleteAtTail()
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

    Node<T> *temp = this->head;
    while (temp->next != this->tail)
        temp = temp->next;
    delete this->tail;
    this->tail = temp;
    this->tail->next = nullptr;
}
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node<T> *current = this->head;
    while (current)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
}