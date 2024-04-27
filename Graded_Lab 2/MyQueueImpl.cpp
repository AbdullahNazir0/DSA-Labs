#include "MyQueue.h"
#include <iostream>
#include <climits>

MyQueue::MyQueue(int size)
{
    if (size <= 0)
        size = 100;
    maxSize = size;
    rear = -1;
    front = -1;
    queueArray = new int[size];
}
void MyQueue::enqueue(int value)
{
    if (full())
    {
        std::cout << "Cannot enqueue, queue full.\n";
        return;
    }

    if (empty)
    {
        front++;
    }
    queueArray[++rear] = value;
}
void MyQueue::dequeue()
{
    if (empty())
    {
        std::cout << "Cannot dequeue, queue is empty.\n";
        return;
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear--;
    }
}
void MyQueue::display() const
{
    if (empty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    for (int i = front; i <= rear; i++)
        std::cout << queueArray[i] << " ";
    std::cout << "\n";
}
bool MyQueue::empty() const
{
    return (front == -1 && rear == -1);
}
bool MyQueue::full() const
{
    return (rear == maxSize - 1);
}
int MyQueue::size() const
{
    return (rear + 1 - front);
}
int MyQueue::back() const
{
    return (queueArray[rear]);
}
void MyQueue::secondLargestAndSmallest()
{
    if (empty() || front == rear || size() == 1)
        return;

    int largest = INT_MIN;
    int smallest = INT_MAX;
    int secondLargest = INT_MIN;
    int secondSmallest = INT_MAX;

    for (int i = front; i <= rear; i++)
    {
        if (queueArray[i] > largest)
        {
            secondLargest = largest;
            largest = queueArray[i];
        }
        else if (queueArray[i] > secondLargest && queueArray[i] != largest)
        {
            secondLargest = queueArray[i];
        }

        if (queueArray[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = queueArray[i];
        }
        else if (queueArray[i] < secondSmallest && queueArray[i] != smallest)
        {
            secondSmallest = queueArray[i];
        }
    }
    std::cout << "Second largest: " << secondLargest << "\n";
    std::cout << "Second smallest: " << secondSmallest << "\n";
}

void MyQueue::rotateFromFront()
{
    if (empty() || size() == 1)
        return;

    int temp = queueArray[front++];
    enqueue(temp);
}
MyQueue::~MyQueue()
{
    if (queueArray)
    {
        delete[] queueArray;
        queueArray = nullptr;
    }
    rear = -1;
    front = -1;
    maxSize = 0;
}