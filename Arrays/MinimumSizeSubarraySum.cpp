// Given an array of positive integers nums and a positive integer target, return the minimal length of a
//  contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to
//   target. If there is no such subarray, return 0 instead.

#include<iostream>
#include<vector>
using namespace std;

 int minSubArrayLen(int target, vector<int>& nums) {
        int min_window = INT_MAX, count=0,i=0,sum=0,tempsum = 0;
        for(i=0;i<nums.size();i++)
        {
            sum += nums[i];
            count++;
            
            if(sum>=target)
            {
                while(sum>=target)
                {
                    tempsum = sum - nums[i-count+1];
                    if(tempsum<target)
                    {
                        if(count<min_window)
                            min_window = count;
                        count--;
                    }
                    else
                        count--;
                    sum = tempsum;
                }
            }
        }
        return (min_window<INT_MAX)?min_window:0;
    }

int main()
{
    vector<int> nums;
    int target=7;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    cout<<"Minimum size subarray: "<<minSubArrayLen(target,nums);
    return 0;
}