#ifndef H_Queue
#define H_Queue

class Queue
{
public:
    Queue() {}
    virtual void enqueue(int) = 0;
    virtual void dequeue() = 0;
    virtual void display() const = 0;
    ~Queue() {}

protected:
    int *queueArray;
    int maxSize;
    int front;
    int rear;
};

#endif