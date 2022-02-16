/* A 2-D array of 1's and 0's is given. Find the row with max 1's in Time Complexity O(nlogn) and Space 
Complexity O(1) . The array is sorted row wise (all 0's in a row are followed by all 1's */

#include<iostream>
#include<vector>
using namespace std;

void maxOne(vector<vector<int>> &matrix)
{
    int count = 0, max = 0,index=0,start = 0,end = matrix[0].size()-1,mid = 0;
    for(int i=0;i<matrix.size();i++)
    {
        while(start<=end)
        {
            mid = start + (end - start)/2;
            if(matrix[i][mid] ==1)
            {
                count += end-mid+1;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        if(max<count)
        {
            max = count;
            index = i;
        }
        start = 0;end = matrix[0].size()-1;count=0;
    }
    cout<<"Max number of one's: "<< max<<" at row index: "<<index<<endl;
}
int main()
{
    vector<vector<int>> matrix;
    vector<int> v1,v2,v3,v4;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);

    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);

    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);

    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);

    maxOne(matrix);
}