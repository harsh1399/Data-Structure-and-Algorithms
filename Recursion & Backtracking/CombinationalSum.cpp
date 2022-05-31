// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void targetPermutations(vector<int> &candidates,int sum,int target,int index,vector<int> values,vector<vector<int>> &result)
    {
        if(sum==target)
        {
            result.push_back(values);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            int temp = sum+candidates[i];
            if(temp<=target){
                values.push_back(candidates[i]);
                targetPermutations(candidates,temp,target,i,values,result);
                temp = sum - candidates[i];
                values.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> values;
        vector<vector<int>> result;
        targetPermutations(candidates,0,target,0,values,result);
        // set<vector<int>> :: iterator itr;
        // for(itr = res.begin();itr!=res.end();itr++)
        // {
        //     vector<int> a = *itr;
        //     result.push_back(a);
        // }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    s.combinationSum(v,7);
    return 0;
}