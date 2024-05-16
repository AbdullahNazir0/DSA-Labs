#ifndef H_Queue
#define H_Queue

#include <iostream>

class Queue
{
public:
    Queue() {}
    virtual void enqueue(Node *) = 0;
    virtual Node *dequeue() = 0;
    ~Queue() {}

protected:
    int maxSize;
    int queueFront;
    int queueRear;
    Node **queueArray;
};

#endif