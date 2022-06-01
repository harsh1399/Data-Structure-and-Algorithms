
#include<iostream>
#include<vector>
using namespace std;

bool escapeMaze(vector<vector<int>> &maze, vector<vector<int>> &path,int row, int col)
{
    if(row == maze.size()-1 && col == maze[0].size()-1)
    {
        path[row][col] = 1;
        return true;
    }
    path[row][col]=1;
    if(col!=maze[0].size()-1)
    {
        if(maze[row][col+1] == 0)
        {
            if(escapeMaze(maze,path,row,col+1))
                return true;
        }
    }
    if(row!=maze.size()-1)
    {
        if(maze[row+1][col]==0)
        {
            if(escapeMaze(maze,path,row+1,col))
                return true;
        }
    }
    path[row][col]=0;
    return false;
}
int main()
{
    vector<vector<int>> maze{{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0}};
    vector<int> v1{0,0,0,0,0};
    vector<vector<int>> path;
    path.push_back(v1);
    path.push_back(v1);
    path.push_back(v1);
    path.push_back(v1);
    path.push_back(v1);

    cout<<"Is escape possible? "<<escapeMaze(maze,path,0,0);
    return 0;

}