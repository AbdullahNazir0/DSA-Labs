#ifndef H_Node
#define H_Node

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

#endif