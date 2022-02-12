/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you 
cannot achieve any profit, return 0. */

#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,profit=0;
        int *right_max = new int[prices.size()];
        right_max[prices.size()-1] = prices[prices.size()-1];
        for(int i = prices.size()-2;i>=0;i--)
        {
            if(prices[i+1]>right_max[i+1])
                right_max[i] = prices[i+1];
            else
                right_max[i] = right_max[i+1];
        }
        for(int i=0;i<prices.size();i++)
        {
            if(( right_max[i] - prices[i]) > profit)
                profit = right_max[i] - prices[i];
        }
        return profit;
    }
    int main()
    {
        int days;
        vector<int> prices;
        cout<<"Enter number of days: ";
        cin>> days;
        cout<<endl<<"Enter prices for each day"<<endl;
        int price;
        for(int i=0;i<days;i++)
        {
            cin>>price;
            prices.push_back(price);
        }
        cout<<endl<<"Max Profit:"<<maxProfit(prices);
        return 0;
    }