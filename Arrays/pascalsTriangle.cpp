#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascalTriangle(int numRows){
    vector<vector<int>> rows(numRows);
    for(int i=0;i<numRows;i++)
    {
        rows[i].resize(i+1);
        rows[i][0] = rows[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            rows[i][j] = rows[i-1][j] + rows[i-1][j-1];
        }
    }
    return rows;
}
int main()
{
    pascalTriangle(5);
    return 0;
}