/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements in O(n) Time complexity and O(1) Space complexity with single traversal allowed */

#include<iostream>
void swap(int* arr, int a,int b)
{
    int temp = arr[b];
    arr[b]=arr[a];
    arr[a]= temp;
}
void shiftZero(int *arr, int n)
{
    int low=0,mid=0;
    while(mid<n)
    {
        if(arr[mid]!=0)
        {
            swap(arr,mid,low);
            low++;
            mid++;
        }
        else
            mid++;
    }
}
//another method
/* void MoveZeroToEnd(int *arr,int n)
{
    int count = 0;
    for (int i=0;i<n;i++)
    {
        if(arr[i]!=0)
            arr[count++] = arr[i];
    }
    while(count<n)
        arr[count++] = 0;
} */

int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	shiftZero(arr,n);
    for (int i = 0; i < n; i++)
		std::cout << arr[i];
    return 0;
}