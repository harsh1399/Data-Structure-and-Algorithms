// You are given an array of integers nums, there is a sliding window of size k which is moving from the 
// very left of the array to the very right. You can only see the k numbers in the window. Each time the 
// sliding window moves right by one position.

// Return the max sliding window.

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> max_index;
    vector<int> maximums;
    for(int i=0;i<nums.size();i++)
    {
        int start_index = i-k+1;
        if(!max_index.empty() && max_index.front()<start_index)
            max_index.pop_front();
            
        while(!max_index.empty() && nums[max_index.back()]<nums[i])
            max_index.pop_back();    
                
        max_index.push_back(i);
        if(i>=k-1)
            maximums.push_back(nums[max_index.front()]);
    }
    return maximums;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);

    vector<int> maximums = maxSlidingWindow(nums,3);
    for(int i=0;i<maximums.size();i++)
        cout<<maximums[i]<<" ";
    return 0;
}