#ifndef stack_H_
#define stack_H_

class stack{
    int size,top;
    int *arr;
    public:
    stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[this->size];
    }
    void push(int val);
    int pop();
    bool isEmpty();
    bool isFull();
};

#endif