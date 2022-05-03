#include<iostream>
#include"../HeaderFiles/queue.h"

using namespace std;

int main()
{
    queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    cout<<"is empty?? "<<q1.isEmpty()<<endl;
    cout<<"is Full?? "<<q1.isFull()<<endl;
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout<<"is empty?? "<<q1.isEmpty()<<endl;
    cout<<"is Full?? "<<q1.isFull()<<endl;

    cout<<"next value "<<q1.dequeue()<<endl;
    cout<<"next value "<<q1.dequeue()<<endl;
    cout<<"next value "<<q1.dequeue()<<endl;
    cout<<"next value "<<q1.dequeue()<<endl;
    cout<<"next value "<<q1.dequeue()<<endl;
    cout<<"is Full?? "<<q1.isFull()<<endl;

    return 0;
}