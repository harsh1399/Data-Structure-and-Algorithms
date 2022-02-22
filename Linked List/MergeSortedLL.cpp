/* Given two sorted linked lists, merge them so that the resulting linked list is also sorted in Time 
Complexity O(n) and Space Complexity(1)  */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

Node* mergeSortedLL(LinkedList list1, LinkedList list2)
{
    Node *temp,*head,*fast,*slow,*second;
    if(list1.head->data < list2.head->data)
    {
        head = list1.head;
        second = list2.head;
    }
    else{
        head = list2.head;
        second = list1.head;
    }
    fast = head->next;
    slow = head;
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
    return head;
}

int main()
{
    LinkedList list1,list2,merged;
    list1.insert(3);
    list1.insert(7);
    list1.insert(8);
    //list1.insert();

    list2.insert(1);
    list2.insert(2);
    list2.insert(5);
    list2.insert(8);
    list2.insert(10);
    list2.insert(11);

    cout<<"list1"<<endl;
    list1.print_list();
    cout<<endl<<"list2"<<endl;
    list2.print_list();
    cout<<endl;
    merged.head = mergeSortedLL(list1,list2);
    merged.print_list();
}