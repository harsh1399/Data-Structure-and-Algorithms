// The median is the middle value in an ordered integer list. If the size of the list is even, there is no 
// middle value and the median is the mean of the two middle values.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
// LEETCODE - #295

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class MedianFinder {
public:
    vector<int> maxheap,minheap;
    int count_max,count_min;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    MedianFinder() {
        count_max = 0;
        count_min = 0;
    }
    void heapifyup_max(int i){
        if(maxheap[i]>maxheap[(i-1)/2] && i)
        {
            int temp = maxheap[(i-1)/2];
            maxheap[(i-1)/2] = maxheap[i];
            maxheap[i] = temp;
            heapifyup_max((i-1)/2);
        }
    }
    void heapifydown_max(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if(left<maxheap.size() && maxheap[left]>maxheap[largest])
            largest = left;
        if(right<maxheap.size() && maxheap[right]>maxheap[largest])
            largest = right;
        
        if(largest!=i){
            int temp = maxheap[largest];
            maxheap[largest] = maxheap[i];
            maxheap[i] = temp;
            heapifydown_max(largest);
        }
    }
    void popTopMaxHeap(){
        int temp = maxheap[0];
        temp = maxheap[maxheap.size()-1];
        maxheap[maxheap.size()-1] = maxheap[0];
        maxheap[0] = temp;
        maxheap.pop_back();
        heapifydown_max(0);
    }
    void heapifyup_min(int i){
        if(minheap[i]<minheap[(i-1)/2] && i)
        {
            int temp = minheap[(i-1)/2];
            minheap[(i-1)/2] = minheap[i];
            minheap[i] = temp;
            heapifyup_min((i-1)/2);
        }
    }
    void heapifydown_min(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;
        if(left<minheap.size() && minheap[left]<minheap[smallest])
            smallest = left;
        if(right<minheap.size() && minheap[right]<minheap[smallest])
            smallest = right;
        
        if(smallest!=i){
            int temp = minheap[smallest];
            minheap[smallest] = minheap[i];
            minheap[i] = temp;
            heapifydown_min(smallest);
        }
    }
    void popTopMinHeap(){
        int temp = minheap[0];
        temp = minheap[minheap.size()-1];
        minheap[minheap.size()-1] = minheap[0];
        minheap[0] = temp;
        minheap.pop_back();
        heapifydown_min(0);
    }
    void addNum(int num) {
        if(maxheap.size() == 0 && minheap.size()==0){
            maxheap.push_back(num);
            count_max++;
        }
        else{
            if(maxheap[0]>num){
                maxheap.push_back(num);
                count_max++;
                heapifyup_max(maxheap.size()-1);
                if(count_max-count_min>1){
                    int element = maxheap[0];
                    popTopMaxHeap();
                    minheap.push_back(element);
                    heapifyup_min(minheap.size()-1);
                    count_max--;
                    count_min++;
                }
            }
            else{
                minheap.push_back(num);
                count_min++;
                heapifyup_min(minheap.size()-1);
                if(count_min - count_max>1){
                    int element = minheap[0];
                    popTopMinHeap();
                    maxheap.push_back(element);
                    heapifyup_max(maxheap.size()-1);
                    count_min--;
                    count_max++;
                }
            }
        }
    }
    double findMedian() {
        cout<<count_max<<" "<<count_min<<endl;
        if(count_max==count_min){
            return (double(maxheap[0])+double(minheap[0]))/2;
        }
        return (count_max>count_min)?maxheap[0]:minheap[0];
    }

    // void addNum(int num)     //implemented through priority queue stl
    // {
    //     if(max_heap.empty() || max_heap.top()>num) max_heap.push(num);
    //     else
    //         min_heap.push(num);
    //     if(max_heap.size()-min_heap.size()>1)
    //     {
    //         min_heap.push(max_heap.top());
    //         max_heap.pop();
    //     }
    //     else if(min_heap.size()-max_heap.size()>1){
    //         max_heap.push(min_heap.top());
    //         min_heap.pop();
    //     }
    // }
    // double findMedian(){
    //     if(max_heap.size()==min_heap.size()){
    //         return (double(max_heap.top())+double(min_heap.top()))/2;
    //     }
    //     return (max_heap.size()>min_heap.size())?max_heap.top():min_heap.top();
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder obj;
    obj.addNum(1);
    obj.addNum(2);
    obj.findMedian();
    obj.addNum(3);
    obj.findMedian();
}