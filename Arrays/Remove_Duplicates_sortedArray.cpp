/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. 
Do not allocate extra space for another array, Time complexity O(n) and Space complexity O(1) */

#include<iostream>

int removeDuplicates(int *arr, int size)
{
    int i=0,j=0;
    if(size == 1 || size ==0 )
        return size;
    for(i=0;i<size-1;i++)
    {
        if(arr[i]!=arr[i+1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[size-1];
    return j;
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
	std::cout << "New array length after removing duplicate elements: "<<removeDuplicates(arr,n);
    return 0;
}