/* Find kth smallest element in that in an unsorted integer array in Time Complexity O(n) and 
Space Complexity O(1)  */

#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr,int low,int high)
{
    int i=0,j=0;
    int pivot = arr[high-1];
    for(i=0;i<high;i++)
    {
        if(arr[i]<pivot)
        {
            if(i!=j)
                swap(&arr[i],&arr[j]);
            j++;
        }      
    }
    swap(&arr[j],&arr[high-1]);
    return j;
}
int kthElement(int *arr,int low,int high, int k)
{
    if(low<high)
    {
        int pivot_index = partition(arr,low,high);
        if(pivot_index == k)
        {
            return arr[k-1];
        }
        if(k<pivot_index)
            return kthElement(arr,low,pivot_index,k);
        else
            return kthElement(arr,pivot_index+1,high,k);
    }
    return -1;
}

int main(){
    int n,index,k_smallest;
	std::cout << "Enter Array Length: ";
	std::cin >> n;
	int *arr = new int[n];
	std::cout << "Enter array elements:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << "Enter K: ";
    cin>>k_smallest;
    cout<<k_smallest<<" smallest element is: "<<kthElement(arr,0,n,k_smallest);
	return 0;

}