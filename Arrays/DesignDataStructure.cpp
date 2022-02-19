/* Design a data structure which performs the following operations(Insert an element/Remove an element 
/find random element/search element) in O(1) time complexity  */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stdlib.h>
using namespace std;

class DS
{
    private:
    vector<int> arr;
    unordered_map<int,int> hashmap;
    public:
    void insert(int element)
    {
        int size = arr.size();
        arr.push_back(element);
        hashmap[element]=size;
    }
    void remove(int element)
    {
        int index = hashmap[element];
        hashmap.erase(element);
        int last_element = arr[arr.size()-1];
        swap(&arr[index],&arr[arr.size()-1]);
        arr.pop_back();
        if(index != arr.size())
            hashmap[last_element] = index;
    }
    int find_random()
    {
        int random = rand() % arr.size();
        return arr[random];
    }
    int search(int element)
    {
        int index = hashmap[element];
        return arr[index];
    }
    void swap(int *a,int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void print_arr()
    {
        cout<<endl;
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
    }
};
int main()
{
    DS a1;
    a1.insert(4);
    a1.insert(5);
    a1.insert(2);
    a1.insert(3);
    a1.insert(1);

    cout<<"element 1:"<<a1.search(1)<<endl;
    cout<<"element 5:"<<a1.search(5)<<endl;
    cout<<"element 3:"<<a1.search(3)<<endl;

    cout<<"random"<<a1.find_random()<<endl;
    cout<<"random"<<a1.find_random()<<endl;

    a1.remove(1);
    a1.remove(5);

    a1.print_arr();

}
    
