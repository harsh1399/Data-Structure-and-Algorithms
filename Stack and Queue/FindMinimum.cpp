// Design a data structure which support push()/pop()/findminimum() operation in O(1) 

#include<iostream>
#include<stack>
using namespace std;
int minElement = INT_MAX;
stack<int> stk;
void findMinimum()
{
    if(stk.empty())
        cout<<"stack is empty"<<endl;
    else
        cout<<"Min element: "<<minElement<<endl;
}
void push(int x)
{
    if(stk.empty()){
        stk.push(x);
        minElement = x;
    }
    else if(x<minElement)
    {
        stk.push(2*x-minElement);
        minElement = x;
    }
    else{
        stk.push(x);
    }
}
void pop()
{
    int tp = stk.top();
    if(tp<minElement)
    {
        minElement = 2*minElement - tp;
        stk.pop();
    }
    else
        stk.pop();
}

int main()
{
    push(3);
    push(5);
    findMinimum();
    push(2);
    push(1);
    push(1);
    push(-1);
    findMinimum();
    pop();
    findMinimum();
    pop();
    findMinimum();
    pop();
    findMinimum();
    return 0;
}