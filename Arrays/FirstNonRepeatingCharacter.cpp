// Given a stream of characters, find the first non-repeating character from stream. You need to tell 
// the first non-repeating character in O(1) time at any moment

#include<iostream>
using namespace std;

int tracker[26]={};
int count=1;

char returnMinimum()
{
    int min = INT_MAX;
    char ch;
    for(int i=0;i<26;i++)
    {
        if(tracker[i]!=0)
        {
            if(min>tracker[i])
            {
                min = tracker[i];
                ch = 'a'+ i;
            }
        }
    }
    return ch;
}
void firstNonRepeating(string stream)
{
    for(int i=0;i<stream.length();i++)
    {
        char ch = stream[i];
        int ascii = int(ch) - 'a';
        if(tracker[ascii] == 0)
            tracker[ascii] = count++;
        else{
            tracker[ascii] = INT_MAX;
        }
        cout<<"Reading charater:"<<ch<<endl;
        cout<<"Non repeating character till now: "<<returnMinimum()<<endl;
    }
}
int main()
{
    string stream = "geeksforgeeks";
    firstNonRepeating(stream);
}