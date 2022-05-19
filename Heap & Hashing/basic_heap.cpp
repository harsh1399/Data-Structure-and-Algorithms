#include<iostream>
#include "../HeaderFiles/MinHeap.h"

using namespace std;

int main()
{
    MinHeap pq;
    pq.push(5);
    pq.push(9);
    pq.push(3);

    cout<<"size: "<<pq.size()<<endl;
    cout<<"Minimum: "<<pq.minimum()<<endl;

    pq.push(8);
    pq.push(6);
    pq.push(20);
    pq.push(10);
    pq.pop();
    cout<<"size: "<<pq.size()<<endl;
    cout<<"Minimum: "<<pq.minimum()<<endl;

    pq.pop();
    cout<<"size: "<<pq.size()<<endl;
    cout<<"Minimum: "<<pq.minimum()<<endl;

    int arr[] = {9,5,3,1,2,12,10,13,4};
    pq.buildHeap(arr,9);
    return 0;
}