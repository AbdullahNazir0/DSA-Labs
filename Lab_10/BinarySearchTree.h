#ifndef H_BinarySearchTree
#define H_BinarySearchTree

#include "Node.h"

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() {}
    virtual void insertNode(const T &) = 0;
    virtual void deleteNode(const T &) = 0;
    ~BinarySearchTree() {}

protected:
    Node<T> *root;
};

#endif