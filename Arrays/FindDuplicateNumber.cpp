// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

#include<iostream>
#include<vector>
using namespace std; 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0] ,slow = nums[0];
        fast = nums[nums[fast]];
        slow = nums[slow];
        while(fast!=slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};