#ifndef queue_H_
#define queue_H_

class queue
{
    
    int size,front,rear;
    int *arr;
    public:
    queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[this->size];
    }

    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};

#endif