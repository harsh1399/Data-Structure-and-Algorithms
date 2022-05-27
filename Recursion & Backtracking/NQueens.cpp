// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool checkPosition(vector<string> board,int row,int col,int n){
        int temp_row = row, temp_col = col;
        while(temp_col>=0)
        {
            if(board[row][temp_col]=='Q')
                return false;
            temp_col--;
        }
        temp_col = col;
        while(temp_row>=0 && temp_col>=0){
            if(board[temp_row][temp_col]=='Q')
                return false;
            temp_row--;
            temp_col--;
        }
        temp_row = row;
        temp_col = col;
        while(temp_row<n && temp_col>=0)
        {
            if(board[temp_row][temp_col] == 'Q')
                return false;
            temp_row++;
            temp_col--;
        }
        return true;
    }
    void nqueens(vector<vector<string>> &result,vector<string> board, int col,int n){
        if(col>=n){
            result.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(checkPosition(board,i,col,n)){
                board[i][col] = 'Q';
                nqueens(result,board,col+1,n);        
                board[i][col] = '.';
            }   
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        //cout<<row[0][0]<<endl;
        vector<vector<string>> result;
        nqueens(result,board,0,n);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
    return 0;
}