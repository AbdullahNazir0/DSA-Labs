#ifndef H_Heap
#define H_Heap

#include "utility.h"

class Heap
{
public:
    Heap() {}
    Heap(int maxSize) : maxSize(maxSize) {}
    virtual void insert(int) = 0;
    virtual void display() const = 0;
    ~Heap() {}

protected:
    int *heapArray;
    int heapSize;
    int maxSize;
};

#endif