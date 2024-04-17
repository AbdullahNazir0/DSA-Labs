#include "MyQueue.h"
#include <iostream>

MyQueue::MyQueue(int size)
{
    maxSize = size;
    front = -1;
    rear = -1;
    queueArray = new int[size];
}
MyQueue::MyQueue(const MyQueue &obj)
{
    maxSize = obj.maxSize;
    front = obj.front;
    rear = obj.rear;
    queueArray = new int[obj.maxSize];
    for (int i = 0; i < maxSize; i++)
        queueArray[i] = obj.queueArray[i];
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
    if (empty())
    {
        return 0; // If the queue is empty, size is 0
    }
    return (rear - front + 1);
}
int MyQueue::back() const
{
    if (empty())
        return -1;
    return (queueArray[rear]);
}
void MyQueue::enqueue(int value)
{
    if (full())
    {
        std::cout << "Queue is full. Cannot enqueue more elements." << std::endl;
        return;
    }
    if (empty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queueArray[rear] = value;
}
int MyQueue::dequeue()
{
    if (empty())
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1;
    }
    int dequeuedValue = queueArray[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return dequeuedValue;
}
void MyQueue::display() const
{
    if (empty())
    {
        std::cout << "No data in queue(empty).\n";
        return;
    }
    std::cout << "Queue Data: ";
    for (int i = front; i <= rear; i++)
        std::cout << queueArray[i] << " ";
    std::cout << "\n";
}
int MyQueue::largest() const
{
    if (empty())
    {
        std::cout << "Cannot find largest element in an empty queue.\n";
        return -1;
    }
    int largest = queueArray[front];
    for (int i = front; i <= rear; i++)
    {
        if (queueArray[i] > largest)
            largest = queueArray[i];
    }
    return (largest);
}
int MyQueue::smallest() const
{
    if (empty())
    {
        std::cout << "Cannot find smallest element in an empty queue.\n";
        return -1;
    }
    int smallest = queueArray[front];
    for (int i = front; i <= rear; i++)
    {
        if (queueArray[i] < smallest)
            smallest = queueArray[i];
    }
    return (smallest);
}
int MyQueue::secondLargest() const
{
    if (empty())
    {
        std::cout << "Cannot find the second largest element in an empty queue.\n";
        return -1;
    }

    if (front == rear != -1)
    {
        std::cout << "Queue contains only one element. Second largest does not exist.\n";
        return -1;
    }

    int largest = queueArray[front];
    int secondLargest = queueArray[front];

    for (int i = front; i <= rear; i++)
    {
        if (queueArray[i] > largest)
        {
            secondLargest = largest;
            largest = queueArray[i];
        }
        else if (queueArray[i] > secondLargest && queueArray[i] < largest)
        {
            secondLargest = queueArray[i];
        }
    }

    if (secondLargest == largest)
    {
        std::cout << "Second largest does not exist in the queue.\n";
        return -1;
    }

    return secondLargest;
}
int MyQueue::secondSmallest() const
{
    if (empty())
    {
        std::cout << "Cannot find the second largest element in an empty queue.\n";
        return -1;
    }

    if (front == rear != -1)
    {
        std::cout << "Queue contains only one element. Second largest does not exist.\n";
        return -1;
    }

    int smallest = queueArray[front];
    int secondSmallest = queueArray[front];

    for (int i = front; i <= rear; i++)
    {
        if (queueArray[i] > smallest)
        {
            secondSmallest = smallest;
            smallest = queueArray[i];
        }
        else if (queueArray[i] > secondSmallest && queueArray[i] < smallest)
        {
            secondSmallest = queueArray[i];
        }
    }

    if (secondSmallest == smallest)
    {
        std::cout << "Second smallest does not exist in the queue.\n";
        return -1;
    }

    return secondSmallest;
}
MyQueue::~MyQueue()
{
    if (queueArray)
        delete[] queueArray;
}