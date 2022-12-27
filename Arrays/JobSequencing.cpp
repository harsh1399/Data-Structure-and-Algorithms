// You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

#include<iostream>
#include<algorithm>
using namespace std;
struct job{
    int id,deadline,profit;
};
bool compare(job a, job b)
{
    return a.profit > b.profit;
}
pair<int,int> maxProfit(job arr[],int n){
    sort(arr,arr+n,compare);
    int max_deadline = 0;
    for(int i=0;i<n;i++){
        if(max_deadline<arr[i].deadline)
            max_deadline = arr[i].deadline;
    }
    int deadline_arr[max_deadline];
    for(int i=0;i<max_deadline;i++)
        deadline_arr[i] = -1;
    int count=0,profit = 0;
    for(int i=0;i<n;i++){
        int dead = arr[i].deadline;
        for(int j=dead;j>=0;j--){
            if(deadline_arr[j]==-1){
                deadline_arr[j] = arr[i].id;
                profit += arr[i].profit;
                count++;
                break;
            }
        }
    }
    return make_pair(count,profit);
}
int main(){
    job arr[4] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    pair<int,int> p = maxProfit(arr,4);
    cout<<"count: "<<p.first<<endl;
    cout<<"max profit: "<<p.second<<endl;
    return 0;
}