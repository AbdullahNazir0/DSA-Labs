#ifndef H_Stack
#define H_Stack

class Stack
{
    public:
        Stack(){}
        virtual void push(int) = 0;
        virtual int pop() = 0;
        ~Stack() {}
    protected:
        int *stackArray;
        int maxSize;
        int stackTop;
};

#endif // H_Stack