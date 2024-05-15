#ifndef H_Node
#define H_Node

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(const T &value) : data(value), next(nullptr) {}
};

#endif