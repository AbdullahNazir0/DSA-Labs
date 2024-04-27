#ifndef H_MyQueue
#define H_MyQueue

#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int = 100);
    void enqueue(int) override;
    void dequeue() override;
    void display() const override;
    bool empty() const;
    bool full() const;
    int size() const;
    int back() const;
    void secondLargestAndSmallest();
    void rotateFromFront();
    ~MyQueue();
};

#endif