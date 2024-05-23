#include "DoublyCircularLinkedList.h"

template <typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList() {}
template <typename T>
void DoublyCircularLinkedList<T>::checkPalindrome()
{
    if (!this->head)
    {
        std::cout << "List is empty\n";
        return;
    }
    if(this->head == this->tail)
    {
        std::cout << "Palindrome\n";
        return;
    }

    Node<T> *left = this->head;
    Node<T> *right = this->tail;
    while (left != right && left->next != right)
    {
        if (left->data != right->data)
        {
            std::cout << "Not a palindrome\n";
            return;
        }
        left = left->next;
        right = right->prev;
    }
    std::cout << "Palindrome\n";
}
template <typename T>
DoublyCircularLinkedList<T>::~DoublyCircularLinkedList() {}