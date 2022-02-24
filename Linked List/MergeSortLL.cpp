/* You are given a linked list as input , you need to sort it using merge sort algorithm using merge sort 
in Time Complexity O(nLogn) */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

Node* mergeSortedLL(Node* head, Node* head2)
{
    Node *temp,*fast,*slow,*second,*head_sorted;
    if(head->data < head2->data)
    {
        head_sorted = head;
        second = head2;
    }
    else{
        head_sorted = head2;
        second = head;
    }
    fast = head_sorted->next;
    slow = head_sorted;
    while(fast!=nullptr && second!=nullptr)
    {
        if(second->data >= slow->data && second->data <= fast->data)
        {
            temp = second->next;
            second->next = slow->next;
            slow->next = second;
            second = temp;
            slow = slow->next;
        }
        else
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    if(second!=nullptr)
            slow->next = second;
    return head_sorted;
}
Node* divide(Node* head)
{
    Node *slow=head,*fast=head,*head2;
    if(head->next == nullptr)
        return head;
    while(fast!=nullptr && fast->next->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    head2 = slow->next;
    slow->next = nullptr;
    head = divide(head);
    head2 = divide(head2);
    return mergeSortedLL(head,head2);
}

int main()
{
    LinkedList list;
    list.insert(4);
    list.insert(2);
    list.insert(8);
    list.insert(5);
    list.insert(1);
    list.insert(6);
    list.insert(3);
    list.insert(7);
    
    cout<<"Before merge sort:"<<endl;
    list.print_list();
    cout<<endl<<"After merge sort:"<<endl;
    list.head = divide(list.head);
    list.print_list();
}