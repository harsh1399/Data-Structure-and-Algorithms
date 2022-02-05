/* We rotate an ascending order sorted array at some point unknown to user. So for instance, 3 4 5 6 7 might 
become 5 6 7 3 4. Modify binary search algorithm to find an element in the rotated array in O(log n) time and 
O(1) Space complexity. */

#include<iostream>

int maxValue(const int* arr,int low,int high)
{
    if(high == low+1)
        return (arr[high]>arr[low])?high:low;
    int mid = low +(high-low)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return mid;
    else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
        return maxValue(arr, mid+1, high);
    else
        return maxValue(arr, low,mid-1);
}
int BinarySearch(const int * arr, int low,int high, int key)
{
    if(high<low)
        return -1;
    int mid = low + (high-low)/2;
    if (arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return BinarySearch(arr, low, mid-1, key);
    else
        return BinarySearch(arr, mid+1, high, key);
}
int main()
{
    int n,key,index,index_left,index_right;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements(After rotations):" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Enter element to be searched: ";
	std::cin >> key;
    index = maxValue(arr,0,n-1);
	index_left = BinarySearch(arr, 0,index,key);
    index_right = BinarySearch(arr,index+1,n-1,key);
	if (index_left == -1 && index_right==-1)
		std::cout << "element not found";
	else
		(index_left == -1)?std::cout << "element found at index: "<<index_right : std::cout << "element found at index: "<<index_left ;

	return 0;
}