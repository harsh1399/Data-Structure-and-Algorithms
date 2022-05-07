// Given an input string, reverse the string word by word

#include<iostream>
#include<string>
using namespace std;
void swap(string &s,int low,int high)
{
    char temp = s[low];
    s[low] = s[high];
    s[high] = temp;
}
void reverse(string &s,int low,int high)
{
    while(low<high)
    {
        swap(s,low++,high--);
    }
}
void reverseString(string &s)
{
    int low = 0,high = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            reverse(s,low,high);
            low = i+1;
        }
        else
        {
            high = i;
        }
    }
    reverse(s,low,high);
    reverse(s,0,high);
}
int main()
{
    string s = "Cracking the coding interview";
    reverseString(s);
    cout<<s; 
    return 0;
}