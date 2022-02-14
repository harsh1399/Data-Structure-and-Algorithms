/* Given an array of integers and a number K. Find the count of distinct elements in every window of size K 
in the array in Time Complexity : O(n) and Space Complexity: O(n) */

#include<unordered_map>
#include<iostream>
using namespace std;
void distinctElements(const int *arr,int size,int window_size)
{
    unordered_map<int,int> counts;
    int count;
    for(int i=0;i<window_size;i++)
    {
        if(counts.find(arr[i])!=counts.end())
        {
            counts[arr[i]]++;
        }
        else
        {
            counts[arr[i]] = 1;
        }
    }
    cout<<"Distinct elements from 0"<<" to "<<window_size<<" "<<counts.size()<<endl;
    if(size!=window_size)
    {
        for(int i = window_size;i<size;i++)
        {
            count = counts[arr[i-window_size]];
            count--;
            if(count==0)
                counts.erase(arr[i-window_size]);
            else
                counts[arr[i-window_size]] = count;
            
            if(counts.find(arr[i])!=counts.end())
            {
                counts[arr[i]]++;
            }
            else
            {
                counts[arr[i]] = 1;
            }
            cout<<"Distinct elements from "<<i-window_size+1<<" to "<<i<<" "<<counts.size()<<endl;
        }
    }
}
int main(){
    int n,index,window_size;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Enter window size: ";
    cin>>window_size;
    cout<<"Distinct elements in each window"<<endl;
    distinctElements(arr,n,window_size);
	return 0;

}