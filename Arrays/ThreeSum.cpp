// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> threeSum(vector<int> &nums)
{
    int low,high;
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    for(int i=0;i<nums.size();i++)
    {
        low = i+1;
        high = nums.size()-1;
        int target = 0 - (nums[i]);
        while(low<high){
            if(nums[low]+nums[high]>target)
                high--;
            else if(nums[low]+nums[high]<target)
                low++;
            else{
                vector<int> numbers = {nums[i],nums[low],nums[high]};
                result.push_back(numbers);

                while(low<high && nums[low]==numbers[1])low++;
                while(low<high && nums[high]==numbers[2]) high--;
            }
        }
        while(i<nums.size()-1 && nums[i]==nums[i+1])
            i++;
    }
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    return 0;
}
