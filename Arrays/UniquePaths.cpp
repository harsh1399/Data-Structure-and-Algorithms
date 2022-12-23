// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.
#include<iostream>
#include<vector>
using namespace std;

/*DP Solution*/
/*class Solution {
public:
    int unique(int i,int j,int m, int n,vector<vector<int>> &dp){
        if(dp[i][j] != -1)
            return dp[i][j];
        else if(i == m-1 && j == n-1)
            return 1;
        else if(i>m-1 || j>n-1)
            return 0;
        else 
            return dp[i][j] = unique(i+1,j,m,n,dp)+unique(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return unique(0,0,m,n,dp);
    }
};*/

//Maths solution
class Solution {
public:
    int uniquePaths(int m, int n) {
    //    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        double result = 1;
        for(int i=m+n-2;i>(m-1);i--){
            result *= i;
            
            result /= i-(m-1);
            
        }
        //cout<<result;
        return result;
    }
};

