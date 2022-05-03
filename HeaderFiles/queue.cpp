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