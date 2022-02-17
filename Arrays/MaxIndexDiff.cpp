/* Given an array A[] of N positive integers. The task is to find the maximum of j - i with the constraint 
of A[i] <= A[j]. Time Complexity : O(n) Space Complexity : O(n) */
#include<iostream>
using namespace std;
int maxDifference(const int *arr, int size)
{
    int *right_max = new int[size];
    int *left_min = new int[size];
    int i=0,j=0,diff = INT_MIN;
    right_max[size-1] = size-1;
    left_min[0] = 0;
    
    for(int i=1;i<size;i++)
    {
        if(arr[i]<arr[left_min[i-1]])
            left_min[i] = i;
        else
            left_min[i] = left_min[i-1];
    }
    
    for(int i = size-2;i>=0;i--)
    {
        if(arr[i]>arr[right_max[i+1]])
            right_max[i] = i;
        else
            right_max[i] = right_max[i+1];
    }
    
    while(i<size && j<size)
    {
        if(arr[left_min[j]]>arr[right_max[i]])
        {
            j++;
        }
        else
        {
            if(right_max[i] - left_min[j] > diff)
                diff = right_max[i] - left_min[j];
            i++;
        }
    }
    return diff;
}
int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    cout<<"Max difference: "<<maxDifference(arr,n);
}