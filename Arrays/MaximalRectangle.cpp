
#include<vector>
#include<iostream>
#include<stack>
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

int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> int_mat;
        vector<int> mat;
        int area=0,max_area = INT_MIN;
        for(int i=0;i<matrix[0].size();i++)
            mat.push_back(int(matrix[0][i])-int('0'));
        int_mat.push_back(mat);
        mat.clear();
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                {
                    mat.push_back((matrix[i][j])-int('0')+ int_mat[i-1][j]);
                }
                else
                    mat.push_back(0);
                
            }
            int_mat.push_back(mat);
            mat.clear();
        }
        for(int i=0;i<int_mat.size();i++){
            area = largestRectangleArea(int_mat[i]);
            if(area>max_area)
                max_area = area;
        }
        return max_area;
    }

int main()
{
    vector<vector<char>> matrix;
    vector<char> v1;
    v1.push_back('1');
    // v1.push_back('0');
    // v1.push_back('1');
    // v1.push_back('0');
    // v1.push_back('0');
    matrix.push_back(v1);
    v1.clear();

    // v1.push_back('1');
    // v1.push_back('0');
    // v1.push_back('1');
    // v1.push_back('1');
    // v1.push_back('1');
    // matrix.push_back(v1);
    // v1.clear();

    // v1.push_back('1');
    // v1.push_back('1');
    // v1.push_back('1');
    // v1.push_back('1');
    // v1.push_back('1');
    // matrix.push_back(v1);
    // v1.clear();

    // v1.push_back('1');
    // v1.push_back('0');
    // v1.push_back('0');
    // v1.push_back('1');
    // v1.push_back('0');
    // matrix.push_back(v1);
    // v1.clear();

    cout<<"Max area:"<<maximalRectangle(matrix);
    return 0;
}