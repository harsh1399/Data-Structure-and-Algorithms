
#include<iostream>
#include<vector>
using namespace std;
int candy(vector<int>& ratings) {
        int *left_comp = new int[ratings.size()];
        int *right_comp = new int[ratings.size()];;
        left_comp[0]=1;
        right_comp[ratings.size()-1] = 1;
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                left_comp[i] = left_comp[i-1]+1;
            else
                left_comp[i] = 1;
        }
        for(int i = ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right_comp[i] = right_comp[i+1]+1;
            else
                right_comp[i] = 1;
        }
    
        int candies = 0;
        for(int i=0;i<ratings.size();i++)
        {
            if(left_comp[i]>=right_comp[i])
                candies = candies+left_comp[i];
            else
                candies = candies + right_comp[i];
            
        }
        return candies;
}

int main()
{
    int n,rating;
    vector<int> ratings;
    cout<<"Enter number of students: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter students ratings";
    for(int i=0;i<n;i++)
    {
        cin>>rating;
        ratings.push_back(rating);
    }    
    cout<<"Minimum number of candies required: "<< candy(ratings);
    return 0;
}
