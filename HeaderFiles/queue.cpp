#include<iostream>
#include "queue.h"
bool queue :: isFull()
{
    if(front == 0 && rear == size-1)
        return true;
    return false;
}
void queue :: enqueue(int data)
{
    if(isFull())
       std:: cout<<"Queue Full!!"<<std::endl;
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        arr[rear] = data;
    }    
}
int queue :: dequeue()
{
    if(isEmpty())
        std::cout<<"queue is empty"<<std::endl;
    else{
        int element = arr[front];
        front++;
        return element;
    }
    return -1;
}
bool queue :: isEmpty()
{
    if(front ==-1)
        return true;
    return false;
}

void circularQueue :: enqueue(int data)
{
    if(circularQueue :: isFull())
       std:: cout<<"Queue Full!!"<<std::endl;
    else
    {
        if(front == -1)
            front = 0;
        rear = (rear+1)%(size);
        arr[rear] = data;
    }    
}
int circularQueue :: dequeue()
{
    if(circularQueue :: isEmpty())
        std::cout<<"queue is empty"<<std::endl;
    else{
        int element = arr[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front+1)%size;
        return element;
    }
    return -1;
}
bool circularQueue :: isFull()
{
    if( (front==0 && rear == size-1) || (rear == front-1))
        return true;
    return false;
}
bool circularQueue :: isEmpty()
{
    if(front == -1)
        return true;
    return false;
}