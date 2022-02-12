/* An array is given as Input where ith element is the price of a given stock on day You were permitted to 
complete unlimited transaction. Derive an algorithm to find the maximum profit in O(n) Time complexity 
and O(1) Space Complexity */ 

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(i==prices.size()-1)
            {
                if(buy!=0)
                {
                    sell = prices[i];
                    profit = profit + (sell - buy);
                }
            }
                
            if(prices[i]<prices[i+1])
            {
                if(buy==0)
                    buy = prices[i];
            }
            else
            {
                if(buy!=0)
                {
                    sell = prices[i];
                    cout<<"buy: "<<buy<<" sell: "<<sell<<endl;
                    profit = profit + (sell - buy);
                    buy = 0;
                }
            }
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