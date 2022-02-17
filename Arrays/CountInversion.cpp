/* Given an unsorted Array, Find the count of Inversion required to make this array sorted in Time 
Complexity:O(nlogn) and Space Complexity: O(n)  */

#include<iostream>
using namespace std;
int merge(int *arr,int low,int high,int *result)
{
    int mid = low +(high-low)/2;
    int i = low,j = mid+1,count = 0, k =low;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            count += (mid+1-i);
            result[k++] = arr[j];
            j++;
        }
        else
        {
            result[k++] = arr[i];
            i++;
        }       
    }
    while(i<=mid)
        result[k++] = arr[i++];
    while(j<=high)
        result[k++] = arr[j++];
    for(int l = low;l<=high;l++)
        arr[l] = result[l];
    return count;
}
int divide(int *arr, int low, int high,int *result)
{
    if(low == high)
        return 0;
    int mid = low + (high-low)/2;
    int count = 0;

    count += divide(arr,low,mid,result);
    count += divide(arr,mid+1,high,result);
    count += merge(arr,low,high,result);
    return count;
}
int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
    int *temp = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    cout<<"Inversion count: "<<divide(arr,0,n-1,temp);
}