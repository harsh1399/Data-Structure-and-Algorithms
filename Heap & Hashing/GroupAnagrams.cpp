// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> grps;
    for(int i=0;i<strs.size();i++)
    {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        grps[temp].push_back(strs[i]);
    }
    vector<vector<string>> result;
    unordered_map<string,vector<string>> :: iterator itr;
    for(itr = grps.begin();itr!=grps.end();itr++)
    {
        result.push_back(itr->second);
    }
    return result;
}

int main()
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string>> result = groupAnagrams(strs);
    return 0;
}