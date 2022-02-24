/* Given a Linked List and a number n, write a function that returns the value at the n’th node from the end 
of the Linked List. */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

void nthFromEnd(Node *head,int n)
{
    Node *fast,*slow;
    fast = head;
    slow = head;
    int count = 0;
    while(count<n)
    {
        fast = fast->next;
        count++;
    }
    while(fast!=nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout<<"Nth node from the end of the linked list: "<<slow->data<<endl;
}
int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    nthFromEnd(list.head,4);
}