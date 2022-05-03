#include "../HeaderFiles/stack.h"
#include<iostream>

using namespace std;

int main()
{
    stack s1(5);
    s1.push(1);
    s1.push(2);
    cout<<"is empty?? "<<s1.isEmpty()<<endl;
    cout<<"is Full?? "<<s1.isFull()<<endl;
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<"is empty?? "<<s1.isEmpty()<<endl;
    cout<<"is Full?? "<<s1.isFull()<<endl;

    cout<<"top value"<<s1.pop()<<endl;
    cout<<"top value"<<s1.pop()<<endl;
    cout<<"is Full?? "<<s1.isFull()<<endl;

    return 0;
}