/* Given an array in which all numbers except two are repeated once. (i.e. we have 2n+2 numbers and n 
numbers are occurring twice and the remaining two have occurred once). Find those two numbers in the most 
efficient way */

#include<iostream>
using namespace std;

void twoNonRepeated(const int* arr, int size)
{
    int result = arr[0];
    for(int i=1;i<size;i++)
        result = result ^ arr[i];
    int rightmost_bit = result & ~(result - 1);    //bit masking operation
    int a=0,b=0;
    for(int i=0;i<size;i++)
        if((rightmost_bit & arr[i])!=0)
            a ^= arr[i];
        else
            b ^= arr[i];
    cout<<"Element 1: "<<a<<" Element 2: "<<b<<endl;
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
    twoNonRepeated(arr,n);
    return 0;
}
