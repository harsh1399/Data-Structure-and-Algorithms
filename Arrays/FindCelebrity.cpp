/* You are in a party of N people, where only one person is known to everyone. Such a person may be present 
at the party, if yes, (s)he doesn’t know anyone at the party. Your task is to find the celebrity at the 
party in Time Complexity O(n) */

#include<iostream>
#include<vector>
using namespace std;
bool knows(vector<vector<int>> matrix,int a, int b) 
{ 
    bool know = (matrix[a][b]==1)?true: false; 
    return know;
} 

int findCelebrity(vector<vector<int>> matrix)
{
    int x = 0,y = matrix[0].size();
    while(x<y)
    {
        if(knows(matrix,x,y))
            x++;
        else
            y--;
    }
    for(int i=0;i<matrix.size();i++)
    {
        if(i!=x && (knows(matrix,x,i) || !knows(matrix,i,x)))
            return -1;        
    }
    return x;
}
int main()
{
    vector<vector<int>> matrix;
    vector<int> v1,v2,v3,v4;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(0); 

    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);

    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);
    
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(0);
    
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    //matrix.push_back(v5); 
    cout<<"Celebrity: "<<findCelebrity(matrix);
    return 0;
}
