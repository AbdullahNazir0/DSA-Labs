#ifndef H_MinHeap
#define H_MinHeap

#include "Heap.h"

class MinHeap : public Heap
{
    public:
        MinHeap(int = 15);
        ~MinHeap();

        void insert(int) override;
        void display() const override;

        void deleteMin();
        void heapifyUp(int);
        void heapifyDown(int);
        void heapSort();
};

#endif