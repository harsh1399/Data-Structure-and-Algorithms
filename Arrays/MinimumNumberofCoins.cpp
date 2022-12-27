// Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

#include<iostream>
using namespace std;
int minimumNumberOfCoins(int v){
    int denomination[9] = {1,2,5,10,20,50,100,500,1000};
    int minimumcoins = 0;
    for(int i = 8;i>=0;i--){
        if(v>=denomination[i]){
            minimumcoins += v/denomination[i];
            v = v% denomination[i];
            if(v==0)
                break;
        }
    }
    return minimumcoins;
}
int main(){
    cout<<"minimum coins: "<<minimumNumberOfCoins(70);
}