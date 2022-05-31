// You are given a string and you are supposed to print all the distinct permutations of the string
// or
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

void permutationString(vector<string> &result,string sorted,string permute,
                    unordered_map<char,int> &tracker)
{
    if(permute.size()==sorted.size())
    {
        result.push_back(permute);
        return;
    }
    for(int i=0;i<sorted.size();i++)
    {
        if(tracker.find(sorted[i])==tracker.end())
        {
            tracker[sorted[i]] = 1;
            permute += sorted[i];
            permutationString(result,sorted,permute,tracker);
            permute.erase(permute.size()-1);
            tracker.erase(sorted[i]);
        }
    }
}

// For all possible permutation of nums
// void allPermutations(vector<int> &nums,int start,int end,vector<vector<int>> &result)
//     {
//         if(start==end)
//         {
//             result.push_back(nums);
//             return;
//         }
//         for(int i=start;i<=end;i++)
//         {
//             swap(nums[i],nums[start]);
//             allPermutations(nums,start+1,end,result);
//             swap(nums[i],nums[start]);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> result;
//         allPermutations(nums,0,nums.size()-1,result);
//         return result;
//     }

int main()
{
    string str = "CBA";
    sort(str.begin(),str.end());
    vector<string> result;
    string s="";
    unordered_map<char,int> tracker;
    permutationString(result,str,s,tracker);

}