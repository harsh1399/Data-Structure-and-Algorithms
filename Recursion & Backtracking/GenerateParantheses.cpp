// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generateParantheses(vector<string> &result,string s,int n,int openbracket, int closebracket)
{
    if(closebracket == n)
    {
        result.push_back(s);
        return ;
    }
    else{
        if(openbracket>closebracket){
            s.append("}");
            generateParantheses(result,s,n,openbracket,closebracket+1);
            s.erase(s.size()-1);
        }
        if(openbracket<n){
            s.append("{");
            generateParantheses(result,s,n,openbracket+1,closebracket);
            s.erase(s.size()-1);
        }
    }
}
int main()
{
    vector<string> result;
    string s = "";
    generateParantheses(result,s,2,0,0);
}