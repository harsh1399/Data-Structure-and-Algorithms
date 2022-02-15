/* Find square root of Guven Num without sqrt() function in Time Complexity O(Logn) and No Space Complexity */

#include<iostream>
using namespace std;

int sqrtNum(int num)
{
    if(num == 0 || num ==1)
        return num;
    int start = 1,end = num,mid=0,result;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(mid*mid == num)
            return mid;
        else if(mid*mid<num)
        {
            start = mid+1;
            result = mid;
        }
        else
            end = mid-1;
    }
    return result;
}
int main()
{
    int num;
    cout<<"Enter number: ";
    cin>>num;
    cout<<endl<<"Square root of num "<<num<<" is "<<sqrtNum(num);
    return 0;
}