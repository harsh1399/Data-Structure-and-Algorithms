#include <iostream>
#include "MinHeap.h"
#include<vector>
using namespace std;

int MinHeap :: parent(int i)
{
    return (i-1)/2;
}
int MinHeap :: leftChild(int i)
{
    return (2*i +1);
}
int MinHeap :: rightChild(int i)
{
    return (2*i +2);
}
void MinHeap :: heapifyDown(int i)
{
    int left = leftChild(i);
    int right = rightChild(i);

    int smallest = i;
    if(left<size() && priority_queue[left]<priority_queue[smallest])
        smallest = left;
    if(right<size() && priority_queue[right]<priority_queue[smallest])
        smallest = right;

    if(smallest != i){
        int temp = priority_queue[smallest];
        priority_queue[smallest] = priority_queue[i];
        priority_queue[i] = temp;
        heapifyDown(smallest);
    }
}
void MinHeap:: heapifyUp(int i)
{
    
    if(priority_queue[i]<priority_queue[parent(i)] && i)
    {
        int parnt = parent(i);
        int temp = priority_queue[parnt];
        priority_queue[parnt] = priority_queue[i];
        priority_queue[i] = temp;
        heapifyUp(parnt);
    }
}

int MinHeap :: size()
{
    return priority_queue.size();
}
void MinHeap :: push(int key)
{
    priority_queue.push_back(key);
    heapifyUp(priority_queue.size()-1);
}
int MinHeap :: minimum()
{
    if(size()==0)
        return -1;
    return priority_queue[0];
}
void MinHeap :: pop()
{
    if(size()==0)
        cout<<"No element present";
    else{
        int top = minimum();
        int temp = priority_queue[priority_queue.size()-1];
        priority_queue[priority_queue.size()-1] = priority_queue[0];
        priority_queue[0] = temp;
        priority_queue.pop_back();
        heapifyDown(0);
    }
}

void MinHeap :: buildHeap(int *arr,int size)
{
    int last_internal = (size/2)-1;
    priority_queue.clear();
    for(int i=0;i<size;i++)
        priority_queue.push_back(arr[i]);
    for(int i=last_internal;i>=0;i--)
    {
        heapifyDown(i);
    }
}