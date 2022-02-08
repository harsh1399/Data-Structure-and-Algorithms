/* Write an algorithm to find out next greater number to given number with the same set of digits. */
#include<bits/stdc++.h>
#include<iostream>
void swapElements(int *arr,int a,int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}
void nextGreaterNumber(int *arr,int size)
{
    int k=size-1,index=-1,difference = INT32_MAX,element;
    while(arr[k]<=arr[k-1])
        k--;
    k--;
    if(k>=0){
        element = arr[k];
        for(int i=k+1;i<size;i++)
        {
            if(arr[i]>element)
            {
                if(difference >= arr[i]-element)
                {
                    index = i;
                    difference = arr[i]-element;
                }
            }
        }
        swapElements(arr,k,index);
        std::sort(arr+k+1,arr+size);
    }
}
int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter Number" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    std::cout<<"Next greatest element is: "<<std::endl;
    nextGreaterNumber(arr,n);
    for (int i = 0; i < n; i++)
		std::cout << arr[i];
    return 0;
}