/* Array consist of only 0's, 1's and 2's. Write an algorithm to sort  this array in O(n) time complexity and 
O(1) Space complexity with only one traversal */

#include<iostream>
void swap(int* arr, int a,int b)
{
    int temp = arr[b];
    arr[b]=arr[a];
    arr[a]= temp;
}
void sort(int* arr, int n)
{
    int low,mid,high;
    low = 0;
    high = n-1;
    mid = 0;

    while(mid<=high)
    {
        if (arr[mid] == 1)
            mid++;
        else if(arr[mid] == 0){
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr,high,mid);
            high--;
        }
    }
}

int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements(0's, 1's & 2's):" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	sort(arr,n);
    for (int i = 0; i < n; i++)
		std::cout << arr[i];
    return 0;
}