#ifndef MinHeap_H_
#define MinHeap_H_
#include <vector>
class MinHeap{
    private:
    std::vector<int> priority_queue;
    int parent(int i);
    int rightChild(int i);
    int leftChild(int i);
    void heapifyDown(int i);
    void heapifyUp(int i);

    public:
    int size();
    void push(int key);
    void pop();
    int minimum();
    void buildHeap(int *arr,int size);
};

#endif