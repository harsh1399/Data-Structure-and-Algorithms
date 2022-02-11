/* Given an array of integer, write an efficient algorithm to find majority number in that array in Time 
Complexity O(n) and Space Complexity O(1) */

#include<iostream>
using namespace std;

int majorityElement(int *arr,int size)
{
    int majority = arr[0],count=1;
    for(int i=1;i<size;i++)
    {
        if(arr[i]!=majority)
        {
            count--;
            if(count == 0)
            {
                majority = arr[i];
                count++;
            }
        }
        else
            count++;
    }
    return majority;
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
    cout<<"majority element: "<<majorityElement(arr,n);
    return 0;
}