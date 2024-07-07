#include "MaxHeap.h"

#include <iostream>

MaxHeap::MaxHeap(int maxSize) : Heap(maxSize)
{
    heapSize = 0;
    heapArray = new int[maxSize];
}

MaxHeap::~MaxHeap()
{
    delete[] heapArray;
    heapArray = nullptr;
    heapSize = 0;
}

void MaxHeap::insert(int value)
{
    if (heapSize == maxSize)
        return;

    // heapArray[heapSize++] = value;
    // heapifyUp(heapSize);
    heapArray[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

void MaxHeap::display() const
{
    for (int i = 0; i < heapSize; i++)
        std::cout << heapArray[i] << " ";
    std::cout << "\n";
}

void MaxHeap::deleteMax()
{
    if (heapSize == 0)
        return;

    swap(heapArray[0], heapArray[heapSize - 1]);
    heapSize--;
    heapifyDown(0);
}

void MaxHeap::heapifyUp(int index)
{
    if (index <= 0)
        return;

    if (heapArray[index] > heapArray[(index - 1) / 2])
    {
        swap(heapArray[index], heapArray[(index - 1) / 2]);
        heapifyUp((index - 1) / 2);
    }

    // while (index < 0 && heapArray[index] < heapArray[index / 2 - 1])
    // {
    //     swap(heapArray[index], heapArray[index / 2 - 1]);
    //     index /= 2 - 1;
    // }
}

void MaxHeap::heapifyDown(int index)
{
    // if (index >= heapSize)
    //     return;

    // if (heapArray[index] > heapArray[index * 2 + 1])
    //     swap(heapArray[index], heapArray[index * 2 + 1]);

    // heapifyDown(index * 2 + 1);

    int maxIndex = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < heapSize && heapArray[left] > heapArray[maxIndex])
        maxIndex = left;

    if (right < heapSize && heapArray[right] > heapArray[maxIndex])
        maxIndex = right;

    if (maxIndex != index)
    {
        swap(heapArray[index], heapArray[maxIndex]);
        heapifyDown(maxIndex);
    }
}

void MaxHeap::heapSort()
{
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapifyDown(i);

    // Extract elements from heap one by one
    int originalSize = heapSize;
    for (int i = heapSize - 1; i > 0; i--)
    {
        // Move current root (maximum element) to the end of the sorted portion
        swap(heapArray[0], heapArray[i]);

        // Reduce heap size and heapify root
        heapSize--;
        heapifyDown(0);
    }

    heapSize = originalSize;

    // Reverse the array to get descending order
    for (int i = 0; i < heapSize / 2; i++)
    {
        swap(heapArray[i], heapArray[heapSize - 1 - i]);
    }

}
