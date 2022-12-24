//Given a string s, find the length of the longest  substring without repeating characters.

 #include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maxlen = 0,l=0,r=0;
        while(r<s.length()){
            if(m.find(s[r])!=m.end()){
                if(m[s[r]]>=l){
                    l = m[s[r]]+1;
                }
            }
            m[s[r]] = r;
            maxlen = max(maxlen,(r-l+1));
            r++;
        }
        return maxlen;
    }
};
int main(){
    Solution s;
    string str = "bbbbbb";
    cout<<s.lengthOfLongestSubstring(str);
}