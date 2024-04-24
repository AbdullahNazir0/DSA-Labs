#ifndef H_LinkedList
#define H_LinkedList

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    LinkedList();
    virtual void insertAtTail(int) = 0;
    virtual void deleteAtTail() = 0;

protected:
    Node *head;
    Node *tail;
};

#endif