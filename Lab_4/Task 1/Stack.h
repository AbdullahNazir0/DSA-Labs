#ifndef H_Stack
#define H_Stack

template <class T>
class Stack
{
public:
    virtual void push(T) = 0;
    virtual int pop() = 0;

protected:
    T *stackArray;
    int maxSize;
    int stackTop;
};

#endif