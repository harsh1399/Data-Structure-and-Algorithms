// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> indexes,indexes_right;
    int *left = new int[heights.size()];
    int *right = new int[heights.size()];
    indexes.push(0);
    left[0] = 0;
    for(int i=1;i<heights.size();i++)
    {
        int tp = indexes.top();
        while(heights[tp]>=heights[i])
        {
            indexes.pop();
            if(!indexes.empty())
                tp = indexes.top();
            else
                break;
        }
        if(indexes.empty())
        {
            left[i] = 0;
            indexes.push(i);
        }
        else
        {
            left[i] = tp+1;
            indexes.push(i);
        }
    }
        
    indexes_right.push(heights.size()-1);
    right[heights.size()-1] = heights.size()-1;
    for(int i=heights.size()-2;i>=0;i--)
    {
        int tp = indexes_right.top();
        while(heights[tp]>=heights[i])
        {
            indexes_right.pop();
            if(!indexes_right.empty())
                tp = indexes_right.top();
            else
                break;
        }
        if(indexes_right.empty())
        {
            right[i] = heights.size()-1;
            indexes_right.push(i);
        }
        else
        {
            right[i] = tp-1;
            indexes_right.push(i);
        }
    }
    int max_area = INT_MIN;
    for(int i=0;i<heights.size();i++)
    {
        int area = (right[i]-left[i]+1)*heights[i];
        if(area>max_area)
            max_area = area;
    }
    return max_area;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout<<"Maximum area: "<<largestRectangleArea(v);
    return 0;
}