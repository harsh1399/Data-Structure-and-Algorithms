#include<iostream>
#include<string>
#include<stack>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<int> s1;
    string newstring = s;
    int erasedTillNow=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            s1.push(i);
        else if(s[i]==')')
        {
            if(!s1.empty())
            {
                s1.pop();
            }
            else
            {
                newstring.erase(newstring.begin()+i-erasedTillNow);
                erasedTillNow++;
            }            
        }
    }
    while(!s1.empty())
    {
        int tp = s1.top();
        s1.pop();
        newstring.erase(newstring.begin()+tp-erasedTillNow);
    }
    return newstring;
}
int main()
{
    string s = "))abcd((";
    cout<<"new string: "<<minRemoveToMakeValid(s)<<endl;
    return 0;
}