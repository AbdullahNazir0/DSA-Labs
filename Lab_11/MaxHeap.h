#ifndef H_MaxHeap
#define H_MaxHeap

#include "Heap.h"

class MaxHeap : public Heap
{
public:
    MaxHeap(int = 15);
    ~MaxHeap();

    void insert(int) override;
    void display() const override;

    void deleteMax();
    void heapifyUp(int);
    void heapifyDown(int);
    void heapSort();
};

#endif