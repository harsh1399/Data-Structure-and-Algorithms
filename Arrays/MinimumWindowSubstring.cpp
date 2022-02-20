/* Given two strings string1 and string2 , return the minimum window in string1 which will contain all the 
characters in string2 in Time Complexity O(n) and Space Complexity O(1) */

#include<iostream>
#include<string>
using namespace std;
void findMinWindow(string str, string substr)
{
    int ascii_str[256] = {};
    int ascii_substr[256] = {};
    int start=0,count=0,min_window = INT32_MAX,ascii,start_index=0;
    for(int i=0;i<substr.length();i++)
    {
        ascii = (int)substr.at(i);
        ascii_substr[ascii]++; 
    }
    for(int j=0;j<str.length();j++)
    {
        ascii = (int)str.at(j);
        ascii_str[ascii]++;
        if(ascii_substr[ascii]!=0 && ascii_str[ascii]<=ascii_substr[ascii])
            count++;
        if(count == substr.length())
        {
            while(ascii_substr[(int)str.at(start)]==0 || ascii_str[(int)str.at(start)]>ascii_substr[(int)str.at(start)])
            {
                if(ascii_str[(int)str.at(start)]>ascii_substr[(int)str.at(start)])
                    ascii_str[(int)str.at(start)]--;
                start++;
            }
            int window_length = j-start+1;
            if(window_length<min_window)
            {
                min_window = window_length;
                start_index = start;
            }
        }
    }
    cout<<"Minimum Window: "<<min_window<<" from index: "<<start_index<<" to index: "<<start_index+min_window-1<<endl;
}
int main()
{
    string str,substr;
    cout<<"Enter string: ";
    cin>>str;
    cout<<"Enter substring: ";
    cin>>substr;
    findMinWindow(str,substr);
    return 0;
}