/* you are given a matrix of m x n elements (m rows, n columns), Print all elements of the matrix in 
spiral order in O(m*n) Time Complexity and O(1) Space Complexity */

#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int row_end = matrix.size();
        int col_end = matrix[0].size();
        int row_start = 0, col_start = 0,i;
        cout<<row_end<<" "<<col_end<<endl;
        int j= row_start, k=col_start,l=col_end,m=row_end;
        while(j<m && k<l)
        {
            for(i=k;i<l;i++)
            {
                cout<<matrix[j][i]<<" ";
                spiral.push_back(matrix[j][i]);
            }
            j++;
            for(i=j;i<m;i++)
            {
                cout<<matrix[i][l-1]<<" ";
                spiral.push_back(matrix[i][l-1]);
            }
            l--;
            if(j<m)
            {
                for(i=l-1;i>=k;--i)
                {
                    cout<<matrix[m-1][i]<<" ";
                    spiral.push_back(matrix[m-1][i]);
                }
                m--;
            }
            if(k<l)
            {
                for(i=m-1;i>=j;--i)
                {
                    cout<<matrix[i][k];
                    spiral.push_back(matrix[i][k]);
                }
                k++;
            }
        }
        return spiral;
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
    spiralOrder(matrix);
    return 0;
}