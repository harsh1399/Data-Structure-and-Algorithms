// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        int longest_streak = 0;
        for(int num:nums){
            hashSet.insert(num);
        }
        for(int i=0;i<nums.size();i++){
            int current_num = nums[i],last_num = i==0?INT_MIN:nums[i-1];
            int current_streak = 1;
            if(current_num!=last_num){
                if(hashSet.count(current_num-1)==0){
                    while(hashSet.count(current_num+1)>0){
                        current_num+=1;
                        current_streak += 1;
                    }
                }
                longest_streak = max(longest_streak,current_streak);
            }
        }
        return longest_streak;
    }
};