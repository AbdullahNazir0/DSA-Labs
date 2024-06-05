#ifndef H_MyBinarySearchTree
#define H_MyBinarySearchTree

#include "BinarySearchTree.h"

template <typename T>
class MyBinarySearchTree : public BinarySearchTree<T>
{
public:
    MyBinarySearchTree();
    void insertNode(const T &) override;
    void deleteNode(const T &) override;
    void displayInorder() const;
    void displayPreorder() const;
    void displayPostorder() const;
    int countEdges(const T &) const;
    T findMin() const;
    T findMax() const;
    ~MyBinarySearchTree();

private:
    void helpInsert(Node<T> *&, Node<T> *);
    void helpDelete(Node<T> *, Node<T> *&, const T &);
    Node<T> *findInorderSuccessor(Node<T> *, Node<T> *);
    void inOrder(Node<T> *) const;
    void preOrder(Node<T> *) const;
    void postOrder(Node<T> *) const;
    int helpCount(Node<T> *, const T &) const;
    T helpFindMin(Node<T> *) const;
    T helpFindMax(Node<T> *) const;
    void destroyTree(Node<T> *);
};

#include "MyBinarySearchTreeImpl.cpp"

#endif