/* List of arrival and departure time is given, Find the minimum number of platforms are required 
for the railway as no train waits. */

#include<iostream>
#include<bits/stdc++.h>
int minimumPlatforms(int *arrival,int *departure,int size)
{
    std::sort(arrival,arrival+size);
    std::sort(departure,departure+size);
    int i = 0,j = 0,platforms=0, result = 1;
    while(i<size && j<size)
    {
        if(arrival[i]<departure[j])
        {
            platforms++;
            i++;
            if(platforms>result)
                result = platforms;
        }
        else
        {
            j++;
            platforms--;
        }
    }
    return result;
}
int main()
{
    int n;
	std::cout << "Enter no. of trains: ";
	std::cin >> n;
	int *arrival = new int[n];
    int *departure = new int[n];
	std::cout << "Enter Arrival timings" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> arrival[i];
    std::cout << "Enter Departure timings" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> departure[i];
    std::cout<<"Maximum platforms required: "<<minimumPlatforms(arrival,departure,n)<<std::endl;
    return 0;
}