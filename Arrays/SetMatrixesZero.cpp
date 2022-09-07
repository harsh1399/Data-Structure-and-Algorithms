#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool colf = true,rowf=true;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j==0)
                        colf = false;
                    else if(i==0)
                        rowf = false;
                    else{
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i=matrix.size()-1;i>=0;i--)
            {
                for(int j=matrix[0].size()-1;j>=0;j--)
                {
                    if(matrix[i][0] == 0 || matrix[0][j]==0 )
                    {
                        matrix[i][j] = 0;
                    }
                    if(j==0 && colf == false)
                        matrix[i][j] = 0;
                    if(i ==0 && rowf == false)
                        matrix[i][j] = 0;
                }
            }
            if(colf == false || rowf == false)
                matrix[0][0] = 0;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    vector<int> b;
    b.push_back(5);
    b.push_back(0);
    b.push_back(7);
    b.push_back(8);
    vector<int> c;
    c.push_back(0);
    c.push_back(10);
    c.push_back(11);
    c.push_back(12);
    vector<int> d;
    d.push_back(13);
    d.push_back(14);
    d.push_back(15);
    d.push_back(0);
    mat.push_back(a);
    mat.push_back(b);
    mat.push_back(c);
    mat.push_back(d);
    s.setZeroes(mat);
    return 0;

}