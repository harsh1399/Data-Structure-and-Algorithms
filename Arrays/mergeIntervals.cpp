// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> mintervals;
        vector<int> current;
        current = intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=current[1])
                current[1] = max(current[1],intervals[i][1]);
            else{
                mintervals.push_back(current);
                current = intervals[i];
            }
        }
        mintervals.push_back(current);
        return mintervals;
    }
};