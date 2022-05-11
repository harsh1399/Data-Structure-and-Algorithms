// Given an array, print the Next Greater Element for every element. The Next greater Element for an element a is the first greater element on the right side of a in array. 
// Elements for which no greater element exist, consider next greater element as -1

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int* nextGreaterElement(vector<int> elements)
{
    stack<int> prev_elements;
    int *nextgreater = new int[elements.size()];
    nextgreater[elements.size()-1] = -1;
    prev_elements.push(elements.size()-1);
    for(int i=elements.size()-2;i>=0;i--)
    {
        int tp = prev_elements.top();
        while(elements[i]>elements[tp])
        {
            prev_elements.pop();
            if(prev_elements.empty())
                break;
            tp = prev_elements.top();
        }
        if(prev_elements.empty())
        {
            nextgreater[i] = -1;
            prev_elements.push(i);
        }
        else
        {
            nextgreater[i] = elements[tp];
            prev_elements.push(i);
        }
    }
    return nextgreater;
}
int main()
{
    vector<int> elements;
    elements.push_back(12);
    elements.push_back(8);
    elements.push_back(6);
    elements.push_back(10);
    elements.push_back(7);
    elements.push_back(9);
    elements.push_back(11);
    elements.push_back(1);
    
    int *nextgreater = nextGreaterElement(elements);
    for(int i=0;i<elements.size();i++)
        cout<<nextgreater[i]<<" ";
    
    return 0;
}