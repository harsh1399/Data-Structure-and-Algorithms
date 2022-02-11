/* Array of length n having integers 1 to n with some elements being repeated. Count frequencies of all 
elements from 1 to n in Time Complexity O(n) and Space Complexity O(1)  */

#include<iostream>
using namespace std;
void frequency(int *arr,int size)
{
    int index = 0;
    for(int i=0;i<size;i++)
        arr[i] = --arr[i];
    for(int i=0;i<size;i++)
    {
        if(arr[i]<size)
        {
            index = arr[i];
            arr[index] = arr[index] + size;
        }
        else
        {
            index = arr[i] % size;
            arr[index] = arr[index]+size;
        }
    }
    for(int i=0;i<size;i++)
        cout<<"Frequency of " <<i+1<<": "<<arr[i]/size<<endl;
}

int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    frequency(arr,n);
    return 0;
}