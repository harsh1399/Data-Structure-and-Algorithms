/* You have an array of non-negative integers,you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.Determine if you are able 
to reach the last index in O(n) Time complexity and O(1) Space Complexity */

#include<iostream>

int minJumps(const int* arr, int size)
{
    int maxSteps = arr[0],steps = arr[0],jumps=1;
    for(int i=1;i<size;i++)
    {
        if(size == 1)
            return jumps;
        else if(arr[0]==0)
            return -1;
        steps--;
        maxSteps--;
        if(arr[i]>maxSteps)
            maxSteps = arr[i];
        if(steps == 0 && i!=size -1)
        {
            if(maxSteps == 0 )
                return -1;
            jumps++;
            steps = maxSteps;
        }
    }
    return jumps;
}
int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Min jumps required to reach last element: "<<minJumps(arr,n);
    return 0;
}