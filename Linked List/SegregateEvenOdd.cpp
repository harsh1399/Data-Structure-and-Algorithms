/* Given a Linked List of integers, write a function to modify the linked list such that all even numbers 
appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd 
numbers same. */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

Node* segregateEvenOdd(LinkedList list)
{
    Node *last_even,*temp = list.head,*tail,*slow;
    while(temp!=nullptr)
    {
        if(temp->data % 2 == 0)
            last_even = temp;
        temp = temp->next;
    }
    temp = slow = list.head;
    tail = last_even;
    while(temp != last_even)
    {
        if(temp->data % 2 !=0 && temp == list.head)
        {
            list.head = list.head->next;
            temp->next = tail->next;
            tail->next = temp;
            tail = tail->next;
            temp = list.head;
        }
        else if(temp->data %2 != 0)
        {
            slow->next = temp->next;
            temp->next = tail->next;
            tail->next = temp;
            tail = tail->next;
            temp = slow->next;
        }
        else{
            slow = temp;
            temp = temp->next;
        }
    }
    return list.head;
}
int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(9);
    list.insert(2);
    list.insert(5);
    list.insert(4);
    list.insert(6);
    list.insert(8);
    list.insert(3);
    list.insert(7);
    list.insert(2);

    list.head = segregateEvenOdd(list);
    list.print_list();

    return 0;
}