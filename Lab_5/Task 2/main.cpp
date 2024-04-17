#include <iostream>
#include "MyQueue.h"

using namespace std;

int main()
{

    MyQueue queue;

    int choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new element to the queue\n";
        std::cout << "2. Remove and return the front element from queue\n";
        std::cout << "3. Check if the queue is full\n";
        std::cout << "4. Check if the queue is empty\n";
        std::cout << "5. Return the size of the queue\n";
        std::cout << "6. Display the queue\n";
        std::cout << "7. Return the largest element in the queue\n";
        std::cout << "8. Return the smallest element in the queue\n";
        std::cout << "9. Display 2nd largest and 2nd smallest element of queue\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter the value to enqueue: ";
            std::cin >> value;
            queue.enqueue(value);
            break;
        }
        case 2:
        {
            int dequeuedValue = queue.dequeue();
            if (dequeuedValue != -1)
                std::cout << "Dequeued element: " << dequeuedValue << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Queue is " << (queue.full() ? "full" : "not full") << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Queue is " << (queue.empty() ? "empty" : "not empty") << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Queue size: " << queue.size() << std::endl;
            break;
        }
        case 6:
        {
            queue.display();
            break;
        }
        case 7:
        {
            int largest = queue.largest();
            if (largest != -1)
                std::cout << "Largest element in the queue: " << largest << std::endl;
            break;
        }
        case 8:
        {
            int smallest = queue.smallest();
            if (smallest != -1)
                std::cout << "Smallest element in the queue: " << smallest << std::endl;
            break;
        }
        case 9:
        {
            int secondLargest = queue.secondLargest();
            int secondSmallest = queue.smallest();
            if (secondLargest != -1 && secondSmallest != -1)
                std::cout << "Second largest element: " << secondLargest << "\nSecond smallest element: " << secondSmallest << std::endl;
            break;
        }
        case 0:
        {
            std::cout << "Exiting program...\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}