/* Given an array where every element occurs two times, except one element which occurs only once. Find the 
element that occurs once. Expected time complexity is O(n) and O(1) extra space */

#include<iostream>
using namespace std;

int occurOnce(const int* arr,int size)
{
    int result=arr[0];
    for(int i=1;i<size;i++)
    {
        result = result ^ arr[i]; 
    }
    return result;
}
int main()
{
    int n,index,window_size;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    cout<<"Element occuring once in this array: "<<occurOnce(arr,n);
    return 0;
}
