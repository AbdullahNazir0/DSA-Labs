#ifndef H_Queue
#define H_Queue

class Queue
{
public:
    virtual void enqueue(int) = 0;
    virtual int dequeue() = 0;

protected:
    int *queueArray;
    int maxSize;
    int front;
    int rear;
};

#endif