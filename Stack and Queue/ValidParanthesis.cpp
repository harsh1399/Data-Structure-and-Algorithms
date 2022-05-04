// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool validParanthesis(string str)
{
    stack<char> stk;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            stk.push(str[i]);
        else
        {
            if(str[i]==')')
            {
                if(stk.empty())
                    return false;
                else if(stk.top() != '(' )
                    return false;
                stk.pop();
            }
            else if(str[i] == '}' ){
                if(stk.empty())
                    return false;
                else if(stk.top()!= '{' )
                    return false;
                stk.pop();
            }
            else if(str[i] == ']' )
            {
                if(stk.empty())
                    return false;
                else if(stk.top()!='[')
                    return false;
                stk.pop();
            }
        }
    }
    if(!stk.empty())
        return false;
    return true;
}
int main()
{
    string s = "({}[]){}[({})]";
    cout<<"is valid parantheses?? "<<validParanthesis(s);
    return 0;
}