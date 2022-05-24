// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find 
// two numbers such that they add up to a specific target number. Let these two numbers be 
// numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        int mid = (numbers.size()-1)/2;
        int low=0,high=numbers.size()-1;
        vector<int> result;
        while(low<high)
        {
            if(numbers[low]+numbers[high]<target)
                low++;
            else if(numbers[low]+numbers[high]>target)
                high--;
            else{
                result.push_back(low+1);
                result.push_back(high+1);
                break;
            }
        }
        return result;
    }

int main()
{
    vector<int> vec{2,7,11,15};
    twoSum(vec,9);
}