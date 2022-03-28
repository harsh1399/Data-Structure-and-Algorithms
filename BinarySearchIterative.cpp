#include<iostream>
using namespace std;
int binarySearch(int *arr,int key,int low,int high)
{
    int mid=0;
    while(high<=low)
    {
        mid = low + (high-low)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid]>key)
            high = mid-1;
        else
            low = mid+1;
        
    }
    return -1;
}
int main() {
	int n,key,index;
	cout << "Enter Array Length: ";
	cin >> n;
	int *arr = new int[n];
	cout << "Enter array elements(In sorted order):" << std::endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Enter element to be searched: ";
	cin >> key;
	index = binarySearch(arr, key, 0, n - 1);
	if (index == -1)
		cout << "element not found";
	else
		cout << "element found at index: "<<index;

	return 0;

}