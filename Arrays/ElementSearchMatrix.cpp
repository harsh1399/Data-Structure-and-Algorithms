/* Matrix n*n is given, where all elements in any individual row or column are sorted. In such a matrix, 
we have to find the position of a value in O(n) Time Complexity and O(1) Space Complexity */

#include<iostream>
#include<vector>
using namespace std;
void searchElement(vector<vector<int>> matrix, int value)
{
    int row = 0,column = matrix[0].size()-1;
    while(row<matrix.size() && column>=0)
    {
        if(matrix[row][column]==value)
        {
            cout<<"row: "<<row<<" column:"<<column<<endl;
            return;
        }
        else if(matrix[row][column]>value)
        {
            column--;
        }
        else{
            row++;
        }
    }
    cout<<"Value not found"<<endl;
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
    searchElement(matrix,30);
    return 0;
}
