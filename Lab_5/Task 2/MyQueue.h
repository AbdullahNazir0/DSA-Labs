#ifndef H_MyQueue
#define H_MyQueue

#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int = 100);
    MyQueue(const MyQueue &obj);
    bool empty() const;
    bool full() const;
    int size() const;
    int back() const;
    void enqueue(int) override;
    int dequeue() override;
    void display() const;
    int largest() const;
    int smallest() const;
    int secondLargest() const;
    int secondSmallest() const;
    ~MyQueue();
};

#include "MyQueueImpl.cpp"

#endif