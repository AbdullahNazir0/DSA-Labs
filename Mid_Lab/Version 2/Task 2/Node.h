#ifndef H_Node
#define H_Node

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

#endif