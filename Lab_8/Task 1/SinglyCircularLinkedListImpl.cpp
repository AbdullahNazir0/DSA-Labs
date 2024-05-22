#include "SinglyCircularLinkedList.h"

template <typename T>
SinglyCircularLinkedList<T>::SinglyCircularLinkedList() {}

template <typename T>
void SinglyCircularLinkedList<T>::insertAtHead(T value)
{
    Node<T> *newNode = new Node<T>(value);
    newNode->next = this->head;
    if (!this->head)
        this->tail = newNode;
    this->head = newNode;
    this->tail->next = this->head;
}

template <typename T>
void SinglyCircularLinkedList<T>::deleteAtHead()
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
    }
    else
    {
        Node<T> *nodeToDelete = this->head;
        this->head = this->head->next;
        delete nodeToDelete;
        this->tail->next = this->head;
    }
}

template <typename T>
SinglyCircularLinkedList<T>::~SinglyCircularLinkedList() {}