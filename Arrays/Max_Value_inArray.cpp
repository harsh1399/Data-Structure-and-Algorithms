/* One array of integers is given as an input ,which is initially increasing and then decreasing or it can be 
only increasing or decreasing , you need to find the maximum value in the array in O(Log n) Time complexity
and O(1) Space Complexity */

#include <iostream>

int maxValue(int *arr, int low, int high){
    int mid = low + (high-low)/2;
    if(high==low+1)
        return (arr[high]>arr[low])?high:low;
    else if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
        return mid;
    else if(arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid])
        return maxValue(arr,mid+1,high);
    else
        return maxValue(arr,low,mid-1);
}

int main(){
    int n,index;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements(increasing and then decreasing or only increasing or only decreasing):" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	index = maxValue(arr,0, n - 1);
	std::cout << "Max element found at index: "<<index<< " value: "<<arr[index];

	return 0;

}