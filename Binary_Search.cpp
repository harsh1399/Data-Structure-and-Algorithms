#include<iostream>

int BinarySearch(const int* arr, int key, int low, int high) {
	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;    //calculate mid
	if (arr[mid] == key)                 //check presence of key at mid
		return mid;
	else if (arr[mid] > key)             //check left half of the array
		return BinarySearch(arr, key, low, mid - 1);
	else
		return BinarySearch(arr, key, mid + 1, high);      //check right half of the array
}

int main() {
	int n,key,index;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements(In sorted order):" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Enter element to be searched: ";
	std::cin >> key;
	index = BinarySearch(arr, key, 0, n - 1);
	if (index == -1)
		std::cout << "element not found";
	else
		std::cout << "element found at index: "<<index;

	return 0;

}