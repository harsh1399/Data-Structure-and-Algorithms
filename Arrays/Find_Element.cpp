/* We have an array, we have to find an element before which all elements are less than it, and after which 
all are greater than it. Finally, return the index of the element, if there is no such element, then 
return -1: Time complexity O(n) and Space Complexity O(n) */

#include<iostream>

int leftLessRightMore(const int* arr, int size)
{
    int* left_max = new int[size];
    int* right_min = new int[size];
    int max = INT32_MIN;
    int min = INT32_MAX;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
        left_max[i] = max;
    }
    for(int i=size-1;i>=0;i--)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        right_min[i] = min;
    }
    for(int i=1;i<size-1;i++)
    {
        if(left_max[i] == right_min[i])
            return i;
    }
    return -1;
}
int main() {
	int n,key,index;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "element found at index: "<<leftLessRightMore(arr,n);
	return 0;
}