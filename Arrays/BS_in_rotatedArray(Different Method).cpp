/* We rotate an ascending order sorted array at some point unknown to user. So for instance, 3 4 5 6 7 might 
become 5 6 7 3 4. Modify binary search algorithm to find an element in the rotated array in O(log n) time and 
O(1) Space complexity. */

#include<iostream>

int BinarySearch(const int* arr,int low,int high,int key)
{
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(arr[mid] == key)
        return mid;
    if(arr[mid]>=arr[low])
    {
        if(arr[mid]>key && key>=arr[low])
            return BinarySearch(arr, low,mid-1,key);
        else
            return BinarySearch(arr,mid+1,high,key);
    }
    else
    {
        if(arr[mid]<key && key<=arr[high])
            return BinarySearch(arr,mid+1,high,key);
        else
            return BinarySearch(arr,low,mid-1,key);
    }
}

int main()
{
    int n,key,index;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements(After rotations):" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Enter element to be searched: ";
	std::cin >> key;
	index = BinarySearch(arr, 0,n-1,key);
    
	if (index == -1)
		std::cout << "element not found";
	else
		std::cout << "element found at index: "<<index;

	return 0;
}