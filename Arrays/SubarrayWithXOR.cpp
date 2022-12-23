// Given an array of integers A and an integer B.

// Find the total number of subarrays having bitwise XOR of all elements equals to B.
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int solve(vector<int> &A, int B) {
    int count = 0,xo = 0;
    map<int,int> hashset;
    for(int i=0;i<A.size();i++){
        xo ^= A[i];
        if(xo == B){
            count++;
        }
        int hashing = xo^B;
        if(hashset.find(hashing)!=hashset.end()){
            count += hashset[hashing];
        }
        hashset[xo]++;
    }
    return count;
}
