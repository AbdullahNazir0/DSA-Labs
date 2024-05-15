#ifndef H_Stack
#define H_Stack

template <typename T>
class Stack
{
    public:
        Stack(){}
        virtual void push(const T &) = 0;
        virtual T pop() = 0;
        ~Stack() {}
    protected:
        T *stackArray;
        int maxSize;
        int stackTop;
};

#endif // H_Stack