// You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &nums){
    int sum = 0,sumsquares = 0,original_sum = 0,original_sumsquares = 0;
    pair<int,int> ans;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        sumsquares += nums[i]*nums[i];
        original_sum += (i+1);
        original_sumsquares += (i+1)*(i+1);
    }
    int p_difference = original_sumsquares - sumsquares;
    int s_difference = original_sum - sum;
    ans.first = 0.5*((p_difference/s_difference)+s_difference);
    ans.second = ans.first - s_difference;
    return ans;
}

int main(){
    vector<int> nums {3,1,2,5,3};
    pair<int,int> result = missingAndRepeating(nums);
    cout<<"missing: "<<result.first<<" repeating: "<<result.second;
}