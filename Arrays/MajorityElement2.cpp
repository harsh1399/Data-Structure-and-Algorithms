// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN,num2=INT_MIN,c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(num1 == nums[i])
                c1++;
            else if(num2 == nums[i])
                c2++;
            else if(c1==0){
                num1 = nums[i];
                c1 = 1;
            }
            else if(c2==0){
                num2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        int count1 = 0,count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(num1 == nums[i])
                count1++;
            if(num2 == nums[i])
                count2++;
        }
        vector<int> ans;
        if(count1>floor(nums.size()/3))
            ans.push_back(num1);
        if(count2>floor(nums.size()/3))
            ans.push_back(num2);
        return ans;
    }
};