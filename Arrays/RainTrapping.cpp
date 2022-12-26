/* N non-negative integers representing an elevation map where the width of each bar is 1. Write an 
algorithm to find how much water it is able to trap after raining in Time Complexity O(n) and 
Space Complexity O(n) */

#include<iostream>
using namespace std;

int rainTrap(const int* arr, int size)
{
    int *right_max = new int[size];
    int *left_max = new int[size];
    left_max[1] = arr[0];
    for(int i=2;i<size;i++)
    {
        if(arr[i-1]> left_max[i-1])
        {
            left_max[i] = arr[i-1];
        }
        else
            left_max[i] = left_max[i-1];
    }
    right_max[size-2] = arr[size-1];
    for(int i=size-3;i>=0;i--)
    {
        if(arr[i+1]>right_max[i+1])
            right_max[i] = arr[i+1];
        else
            right_max[i] = right_max[i+1];
    }
    int rain_water = 0;
    for(int i =1; i < size-1;i++)
    {
        if(arr[i]<left_max[i] && arr[i]<right_max[i])
        {
            rain_water += (left_max[i]<right_max[i])?left_max[i] - arr[i] : right_max[i] - arr[i];
        }
    }
    return rain_water;
}

//another solution - O(N) SC - O(1)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res=0,left = 0,right = height.size()-1,leftmax = 0,rightmax = 0;
//         while(left<right){
//             if(height[left]<=height[right]){
//                 if(height[left]>=leftmax)
//                     leftmax = height[left];
//                 else
//                     res += leftmax - height[left];
//                 left++;
//             }
//             else{
//                 if(height[right]>=rightmax){
//                     rightmax = height[right];
//                 }
//                 else
//                     res += rightmax - height[right];
//                 right--;
//             }
//         }
//         return res;
//     }
// };

int main()
{
    int n;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter elevation:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
    cout<<"Rain water trapped: "<<rainTrap(arr,n);
}