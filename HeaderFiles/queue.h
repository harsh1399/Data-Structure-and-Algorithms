#ifndef queue_H_
#define queue_H_
class abstract_queue
{
    public:
    int size,front,rear;
    int *arr;
    public:
    virtual void enqueue(int data)=0;
    virtual int dequeue()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
};
class queue : public abstract_queue
{
    public:
    queue(int size)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[this->size];
    }

    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};

class circularQueue : public abstract_queue{
    public:
    circularQueue(int size)
    {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        arr = new int[this->size];
    }
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};
#endif