#include<iostream>

void merge(int* arr, int* result, int low, int high, int mid) {
	int pointer1=low, pointer2=mid+1, index=low;
	
	while (pointer1 <= mid && pointer2 <= high) {
		if (arr[pointer1] > arr[pointer2]) {
			result[index++] = arr[pointer2++];
		}
		else
		{
			result[index++] = arr[pointer1++];
		}
	}
	while (pointer1 <= mid)
		result[index++] = arr[pointer1++];
	while (pointer2 <= high)
		result[index++] = arr[pointer2++];

	for(int i=low;i<=high;i++)
		arr[i] = result[i];
}

void divide(int *arr,int *result, int low,int high) {
	if (low == high)
		return;
	int mid = low + (high - low) / 2;
	divide(arr, result, low, mid);
	divide(arr, result, mid + 1, high);
	merge(arr, result, low, high, mid);
}
int main()
{
	int n, key, index;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int* arr = new int[n];
	int* result = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	divide(arr, result, 0, n - 1);
	std::cout << "Sorted Array:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout<< arr[i]<<" ";

}