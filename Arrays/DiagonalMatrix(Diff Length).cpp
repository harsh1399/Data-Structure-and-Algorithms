/* Given a matrix of M x N elements (M rows, N columns), Print all elements of the matrix in diagonal order 
in Time Complexity O(m*n) and Space Complexity O(1) */
//Each row of the matrix can be of different length

#include<iostream>
#include<vector>
using namespace std;
vector<int>  diagonal(vector<vector<int>>& nums)
{
    vector<int> diagonal_traverse;
        int j=0,k=0,max = 0;
        for(int i=0;i<nums.size();i++)
        {
            j = i,k=0;
            if(nums[i].size()>max)
                max = nums[i].size();
            while(j>=0 )
            {
                if(nums[j].size()>k)
                {
                    //cout<<nums[j][k]<<" ";
                    diagonal_traverse.push_back(nums[j][k]);    
                }
                j--;k++;
            }
        }
       
        
        for(int i=1;i<max;i++)
        {
            j = nums.size()-1;
            k=i;
            while(j>=0)
            {
                if(nums[j].size()>k)
                {
                    //cout<<nums[j][k]<<" ";
                    diagonal_traverse.push_back(nums[j][k]);
                }
                j--;k++;
            }
        }   
        return diagonal_traverse;
}
int main()
{
    vector<vector<int>> matrix;
    vector<int> v1,v2,v3,v4;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4); 

    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);

    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);

    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);
    
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4); 
    diagonal(matrix);
    return 0;
}
