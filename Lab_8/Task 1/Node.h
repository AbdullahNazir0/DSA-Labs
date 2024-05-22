#ifndef H_Node
#define H_Node

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(nullptr) {}
};

#endif