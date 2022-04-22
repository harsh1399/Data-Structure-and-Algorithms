// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
        int count0 = 0,count1 = 0,i=0,longest1 = 0,index;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(k!=0)
                    count0++;
                if(k==0)
                    count1=0;
            }
            else if(nums[i]==1)
                count1++;
            if(count0<=k)
            {
                if((count0+count1)>longest1)
                    longest1 = count0+count1;
            }
            else if(count0>k)
            {
                while(count0>k)
                {
                    index = i - (count0+count1-1);
                    if(nums[index]==0)
                        count0--;
                    else
                        count1--;
                }
            }   
        }
        return (count0==0 && k!=0)?count1:longest1;
    }

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    cout<<"Max consecutive one's: "<<longestOnes(arr,2);
    return 0;
}