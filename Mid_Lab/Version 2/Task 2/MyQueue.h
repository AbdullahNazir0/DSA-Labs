#ifndef H_MyQueue
#define H_MyQueue

#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int = 100);
    void enqueue(Node *) override;
    Node* dequeue() override;
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    ~MyQueue();
};

#include "MyQueueImpl.cpp"

#endif