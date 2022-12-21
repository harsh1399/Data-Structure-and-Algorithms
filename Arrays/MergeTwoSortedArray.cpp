// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include<iostream>
using namespace std;

void mergeArray(int *arr1,int m, int *arr2, int n){
    int gap = (m+n)/2 + (m+n)%2;
    while(gap>0){
        int ptr1 = 0,ptr2=gap;
        while(ptr2<(m+n)){
            if(ptr2<m && arr1[ptr1]>arr1[ptr2]){
                swap(arr1[ptr1],arr1[ptr2]);
            }
            else if(ptr2>=m && ptr1<m && arr1[ptr1]>arr2[ptr2-m]){
                swap(arr1[ptr1],arr2[ptr2-m]);
            }
            else if(ptr1>=m && ptr2>=m && arr2[ptr1-m] > arr2[ptr2-m]){
                swap(arr2[ptr1-m],arr2[ptr2-m]);
            }
            ptr1++;
            ptr2++;
        }
        if(gap<=1){
            gap = 0;
        }
        else
            gap = (gap/2) + (gap%2);
    }
}
int main(){
    int arr1[] ={1,4,8,10};
    int arr2[]={2,3,9};
    mergeArray(arr1,4,arr2,3); 
    cout<<"arr1"<<endl;
    for(int i=0;i<4;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"arr2"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr2[i]<<" ";
    }
}