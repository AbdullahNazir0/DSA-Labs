#include "MyQueue.h"
#include <iostream>

MyQueue::MyQueue(int size)
{
    this->maxSize = size;
    this->queueFront = -1;
    this->queueRear = -1;
    this->queueArray = new Node *[size];
}

void MyQueue::enqueue(Node *value)
{
    if (isFull())
    {
        std::cout << "Can't enqueue, queue is full. (Queue overflown)\n";
        return;
    }

    if (isEmpty())
        this->queueFront = 0;
    this->queueArray[++this->queueRear] = value;
}

Node *MyQueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Can't dequeue, queue is empty. (Queue underflown)\n";
        return nullptr;
    }

    Node *value = this->queueArray[this->queueFront];
    if (this->queueFront == this->queueRear)
    {
        this->queueFront = -1;
        this->queueRear = -1;
    }
    else
        this->queueFront++;

    return value;
}

bool MyQueue::isFull() const
{
    return (this->queueRear == this->maxSize - 1);
}

bool MyQueue::isEmpty() const
{
    return (this->queueFront == -1);
}

void MyQueue::display() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    for (int i = this->queueFront; i <= this->queueRear; i++)
        std::cout << this->queueArray[i] << " ";
    std::cout << "\n";
}

MyQueue::~MyQueue()
{
    if (this->queueArray)
        delete[] this->queueArray;
}