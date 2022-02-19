/* Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would 
be at the k’th position of the final sorted array Time Complexity: O(log n + log m) */
#include<iostream>
using namespace std;
int kSmallest(int *arr1,int *arr2, int low1, int low2,int high1,int high2, int k)
{
    int mid1,mid2;
    if(low1>high1 || low2>high2)
    {
        return (low1>high1)?arr2[low2]:arr1[low1];
    }
    mid1 = low1 + (high1-low1)/2;
    mid2 = low2 + (high2-low2)/2;
     
    if(arr1[mid1]>arr2[mid2])
    {
        if((mid1+1)+(mid2+1) == k)
            return arr1[mid1];
        else if((mid1+1)+(mid2+1)>k)
            return kSmallest(arr1,arr2,low1,low2,mid1-1,high2,k);
        else
            return kSmallest(arr1,arr2,low1,mid2+1,high1,high2,k);
    }
    else
    {
        if((mid1+1)+(mid2+1) == k)
            return arr2[mid2];
        else if((mid1+1)+(mid2+1)>k)
            return kSmallest(arr1,arr2,low1,low2,high1,mid2-1,k);
        else
            return kSmallest(arr1,arr2,mid1+1,low2,high1,high2,k);
    }
}
int main()
{
    int n,m,k;
	cout << "Enter Array1 Length: ";
	cin >> n;
    cout << "Enter Array2 Length: ";
	cin >> m;
	int *arr1 = new int[n];
    int *arr2 = new int[m];
	cout << "Enter array1 elements in sorted manner:" << endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr1[i];
    cout <<endl<< "Enter array2 elements in sorted manner:" << endl;
	for (int i = 0; i < m; i++)
		std::cin >> arr2[i];
    cout<<"Enter k: ";
    cin>>k;
    cout<<"kth smallest element: "<<kSmallest(arr1,arr2,0,0,n-1,m-1,k);
    return 0;
}