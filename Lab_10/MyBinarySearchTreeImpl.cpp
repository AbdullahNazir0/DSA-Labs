#include "MyBinarySearchTree.h"
#include <iostream>

template <typename T>
MyBinarySearchTree<T>::MyBinarySearchTree()
{
    this->root = nullptr;
}

template <typename T>
void MyBinarySearchTree<T>::insertNode(const T &value)
{
    Node<T> *valueNode = new Node<T>(value);

    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    helpInsert(this->root, valueNode);
}

template <typename T>
void MyBinarySearchTree<T>::deleteNode(const T &value)
{
    if (!this->root)
    {
        std::cout << "Cannot delete from empty BST.\n";
        return;
    }

    if (this->root->data == value) // delete root.
    {
        if (!this->root->left && !this->root->right)
        {
            delete this->root;
            this->root = nullptr;
            return;
        }
        else if (this->root->left && !this->root->right)
        {
            Node<T> *nodeToDelete = this->root;
            this->root = this->root->left;
            delete nodeToDelete;
        }
        else if (!this->root->left && this->root->right)
        {
            Node<T> *nodeToDelete = this->root;
            this->root = findInorderSuccessor(this->root, this->root->right);
            this->root->left = nodeToDelete->left;
            this->root->right = nodeToDelete->right;
            delete nodeToDelete;
        }
        else
        {
            Node<T> *newRoot = findInorderSuccessor(this->root, this->root->right);
            newRoot->left = this->root->left;
            newRoot->right = this->root->right;
            delete this->root;
            this->root = newRoot;
        }
    }

    helpDelete(nullptr, this->root, value);
}

template <typename T>
void MyBinarySearchTree<T>::displayInorder() const
{
    if (!this->root)
    {
        std::cout << "BST is empty.\n";
        return;
    }

    inOrder(this->root);
    std::cout << "\n";
}

template <typename T>
void MyBinarySearchTree<T>::displayPreorder() const
{
    if (!this->root)
    {
        std::cout << "BST is empty.\n";
        return;
    }

    preOrder(this->root);
    std::cout << "\n";
}

template <typename T>
void MyBinarySearchTree<T>::displayPostorder() const
{
    if (!this->root)
    {
        std::cout << "BST is empty.\n";
        return;
    }

    postOrder(this->root);
    std::cout << "\n";
}

template <typename T>
int MyBinarySearchTree<T>::countEdges(const T &value) const
{
    if (!this->root)
        return (-1);

    if (this->root->data == value)
        return (0);

    return (helpCount(this->root, value));
}

template <typename T>
T MyBinarySearchTree<T>::findMin() const
{
    if (!this->root)
    {
        std::cout << "BTS is empty.\n";
        return T();
    }

    return (helpFindMin(this->root));
}

template <typename T>
T MyBinarySearchTree<T>::findMax() const
{
    if (!this->root)
    {
        std::cout << "BTS is empty.\n";
        return T();
    }

    return (helpFindMax(this->root));
}

template <typename T>
MyBinarySearchTree<T>::~MyBinarySearchTree()
{
    destroyTree(this->root);
    this->root = nullptr;
}

// --- priv --- //
template <typename T>
void MyBinarySearchTree<T>::helpInsert(Node<T> *&node, Node<T> *valueNode)
{
    if (node == nullptr)
    {
        node = valueNode;
        return;
    }

    if (node->data == valueNode->data)
    {
        std::cout << "Cannot insert duplicate value in BST.\n";
    }
    else if (node->data < valueNode->data)
    {
        helpInsert(node->right, valueNode);
    }
    else
    {
        helpInsert(node->left, valueNode);
    }
}

template <typename T>
void MyBinarySearchTree<T>::helpDelete(Node<T> *ancestor, Node<T> *&node, const T &value)
{
    if (node == nullptr)
        return;

    if (node->data > value)
        helpDelete(node, node->left, value);
    else if (node->data < value)
        helpDelete(node, node->right, value);
    else if (node->data == value)
    {
        if (!node->left && !node->right) // if leaf
        {
            delete node;
            node = nullptr;
            return;
        }
        if (node->left && !node->right) // if only one child
        {
            if (ancestor->right == node)

                ancestor->right = node->left;
            else
                ancestor->left = node->left;
            delete node;
            return;
        }
        else if (!node->left && node->right) // if only one child
        {
            if (ancestor->right == node)
                ancestor->right = node->right;
            else
                ancestor->left = node->right;
            delete node;
            return;
        }
        else // if two child
        {
            // Node<T> *inOrderSuccessor = findInorderSuccessor(node, node->right);
            // inOrderSuccessor->left = node->left;
            // inOrderSuccessor->right = node->right;
            // if (ancestor->left == node) // left child
            // {
            //     // inOrderSuccessor = node->right;
            //     ancestor->left = inOrderSuccessor;
            // }
            // else
            // {
            //     // inOrderSuccessor = node->right;
            //     ancestor->right = inOrderSuccessor;
            // }
            // delete node;
            // return;

            // Find the in-order successor and its parent
            Node<T> *parentOfSuccessor = this->root;
            Node<T> *inOrderSuccessor = this->root->right;

            // Find the in-order successor (smallest in the right subtree)
            while (inOrderSuccessor->left != nullptr)
            {
                parentOfSuccessor = inOrderSuccessor;
                inOrderSuccessor = inOrderSuccessor->left;
            }

            // If the in-order successor is not the direct right child of the root
            if (parentOfSuccessor != this->root)
            {
                parentOfSuccessor->left = inOrderSuccessor->right;
                inOrderSuccessor->right = this->root->right;
            }

            inOrderSuccessor->left = this->root->left;

            // Delete the old root and replace it with the in-order successor
            delete this->root;
            this->root = inOrderSuccessor;
            return;
        }
    }
}

template <typename T>
void MyBinarySearchTree<T>::inOrder(Node<T> *node) const
{
    if (!node)
        return;

    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

template <typename T>
void MyBinarySearchTree<T>::preOrder(Node<T> *node) const
{
    if (!node)
        return;

    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void MyBinarySearchTree<T>::postOrder(Node<T> *node) const
{
    if (!node)
        return;

    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

template <typename T>
Node<T> *MyBinarySearchTree<T>::findInorderSuccessor(Node<T> *ancestor, Node<T> *node)
{
    if (!node->left)
    {
        if (ancestor->right == node)
        {
            ancestor->right = node->left;
            return node;
        }
        else
        {
            ancestor->left = node->left;
            return node;
        }
    }

    findInorderSuccessor(node, node->left);
}

template <typename T>
int MyBinarySearchTree<T>::helpCount(Node<T> *node, const T &value) const
{
    if (node == nullptr)
        return -1;

    if (node->data == value)
        return 0;

    int leftEdges = helpCount(node->left, value);
    int rightEdges = helpCount(node->right, value);

    if (leftEdges != -1)
        return leftEdges + 1;

    if (rightEdges != -1)
        return rightEdges + 1;

    return -1;
}

template <typename T>
T MyBinarySearchTree<T>::helpFindMin(Node<T> *node) const
{
    if (!node->left)
    {
        return node->data;
    }

    return helpFindMin(node->left);
}

template <typename T>
T MyBinarySearchTree<T>::helpFindMax(Node<T> *node) const
{
    if (!node->right)
    {
        return node->data;
    }

    return helpFindMax(node->right);
}

template <typename T>
void MyBinarySearchTree<T>::destroyTree(Node<T> *node)
{
    // from AI
    if (node != nullptr)
    {
        // Recursively delete the left subtree
        destroyTree(node->left);
        // Recursively delete the right subtree
        destroyTree(node->right);
        // Delete the current node
        delete node;
    }
}