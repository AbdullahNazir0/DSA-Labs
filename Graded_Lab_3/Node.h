#ifndef H_Node
#define H_Node

template <typename T>
struct Node 
{
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
};

#endif