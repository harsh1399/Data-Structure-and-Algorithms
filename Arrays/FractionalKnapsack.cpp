// The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

#include<iostream>
#include<algorithm>
using namespace std;

struct item{
    int weight,value;
};
bool compare(item a,item b)
{
    return a.value/a.weight>b.value/b.weight;
}
int maxValue(item arr[],int n, int weight){
    sort(arr,arr+n,compare);
    int max_value = 0;
    for(int i=0;i<n;i++){
        if(weight == 0)
            break;
        if(arr[i].weight<=weight){
            weight -= arr[i].weight;
            max_value += arr[i].value;
        }
        else{
            max_value += (arr[i].value/arr[i].weight) * weight;
            weight = 0;
        }
    }
    return max_value;
}
int main(){
    item arr[] = {{10,60},{20,100},{30,120}};
    cout<<"max value: "<<maxValue(arr,3,50);
    return 0;
}