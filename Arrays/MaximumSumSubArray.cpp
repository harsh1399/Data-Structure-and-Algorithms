/* Find the contiguous subarray within an array[] of length N which has the largest sum in Time Complexity 
O(n) and Space Complexity O(1) - Kadane Algorithm */
//KADANE ALGORITHM
#include<iostream>
using namespace std;

int maxSubArray(const int *arr, int size)
{
    int local_max = arr[0],global_max = arr[0];
    for(int i=1;i<size;i++)
    {
        local_max = (arr[i] > local_max + arr[i]) ? arr[i]:local_max + arr[i];
        global_max = (local_max>global_max) ? local_max : global_max;
    }
    return global_max;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Maximum sum of subarray: "<<maxSubArray(arr,n);
    return 0;
}