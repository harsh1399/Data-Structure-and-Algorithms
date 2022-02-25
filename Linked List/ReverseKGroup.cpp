/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list in Time 
Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

Node* reverseKNodes(Node* head, int k)
{
    Node *prev= nullptr,*current = head,*next = head;
    int count = 0;
    while(count<k && current!=nullptr)
    {
        next = current->next;
        current->next= prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=nullptr)
        head->next = reverseKNodes(next,k);
    return prev;
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
    list.insert(7);
    list.insert(8);
    cout<<"Before reversing: "<<endl;
    list.print_list();
    cout<<endl<<"After reversing: "<<endl;
    list.head = reverseKNodes(list.head,3);
    list.print_list();
    return 0;
}