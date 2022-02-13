/* Array of both positive and negative numbers, the task is to find out the sub array whose sum is Zero in 
Time Complexity O(n) and Space Complexity O(n) */

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class SubArray{
    public:
    int start_index,end_index;
    SubArray(int a,int b)
    {
        start_index = a;
        end_index =b;
    }
};
vector<SubArray> subArrayZero(const int *arr,int size)
{
    unordered_map<int,vector<int>> sums;
    int sum=0;
    vector<SubArray> result; 
    for(int i=0;i<size;i++)
    {
        vector<int> indexes;
        sum = sum + arr[i];
        if(sum == 0)
        {
            SubArray a(0,i);
            result.push_back(a);
        }
        if(sums.find(sum) != sums.end())
        {
            indexes = sums[sum];
            for(int j=0;j<indexes.size();j++)
            {
                SubArray b(indexes[j]+1,i);
                result.push_back(b);
            }
            sums[sum].push_back(i);
        }
        else
        {
            indexes.push_back(i);
            sums[sum] = indexes;
        }
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<SubArray> result = subArrayZero(arr,n);
    cout<<"SUB ARRAYS WITH SUM ZERO:"<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<"Start Index: "<<result[i].start_index<<" End Index: "<<result[i].end_index<<endl;
    }
    return 0;
}