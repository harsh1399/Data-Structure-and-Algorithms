
#include<iostream>
#include<vector>
using namespace std;
void pmatrix(vector<vector<int>> matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rotate(vector<vector<int>> matrix)
{
    int row_start = 0,row_end= matrix.size()-1,col_start = 0 ,col_end = matrix[0].size()-1;
    int j=0,k=0,l=col_end,m=row_end,temp = 0,z=0;
    while(j<m && k<l)
    {
        for(int i=j;i<l;i++)
        {
            temp = matrix[j][i];
            matrix[j][i] = matrix[m-z][k];
            matrix[m-z][k] = matrix[m][l-z];
            matrix[m][l-z] = matrix[j+z][l];
            matrix[j+z][l] = temp;
            z++;
        }
        j++;k++;m--;l--;
        z=0;
    }
    pmatrix(matrix);
}

int main()
{
    vector<vector<int>> matrix;
    vector<int> v1,v2,v3,v4,v5;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5); 

    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(10);

    v3.push_back(11);
    v3.push_back(12);
    v3.push_back(13);
    v3.push_back(14);
    v3.push_back(15);
    
    v4.push_back(16);
    v4.push_back(17);
    v4.push_back(18);
    v4.push_back(19);
    v4.push_back(20);

    v5.push_back(21);
    v5.push_back(22);
    v5.push_back(23);
    v5.push_back(24);
    v5.push_back(25);
    
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5); 
    pmatrix(matrix);
    cout<<"After rotation:"<<endl;
    rotate(matrix);
    return 0;
}
