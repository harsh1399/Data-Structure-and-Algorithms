/* There are two sorted arrays A and B of same size n(ODD LENGTH). Find the median of the two sorted 
arrays. The overall run time complexity should be O(log n)) and Space Complexity O(1) */

#include<iostream>
using namespace std;
int getMedian(int *arr,int low,int high)
{
    int n = high-low + 1;
    if(n%2==0)
        return (arr[low + n/2] + arr[low + n/2-1])/2;
    else
        return arr[low+n/2];
}
int findMedian(int *arr1,int *arr2, int start_arr1,int end_arr1,int start_arr2,int end_arr2)
{
    float element1,element2,median1,median2;
    if(end_arr1-start_arr1+1 == 1 && end_arr2-start_arr2+1 == 1)
    {
        return (arr1[0]+arr2[0])/2;
    }
    if(end_arr1-start_arr1+1 ==2 && end_arr2-start_arr2+1 ==2)
    {
        element1 = max(arr1[start_arr1],arr2[start_arr2]);
        element2 = min(arr1[end_arr1],arr2[end_arr2]);
        return (element1+element2)/2;
    }
    median1 = getMedian(arr1,start_arr1,end_arr1);
    median2 = getMedian(arr2, start_arr2,end_arr2);
    int mid1 = start_arr1 + (end_arr1 - start_arr1)/2;
    int mid2 = start_arr2 + (end_arr2 - start_arr2)/2;
    if(median1>median2)
        return findMedian(arr1,arr2,start_arr1,mid1,mid2,end_arr2);
    else
        return findMedian(arr1,arr2,mid1,end_arr1,start_arr2,mid2);
    
}


int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr1 = new int[n];
    int *arr2 = new int[n];
	std::cout << "Enter array1 elements in sorted manner:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr1[i];
    std::cout <<endl<< "Enter array2 elements in sorted manner:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr2[i];
    cout<<"Median od two sorted arrays: "<<findMedian(arr1,arr2,0,n-1,0,n-1);
    return 0;
}