/* Write a program to find the node at which the intersection of two singly linked lists begins. */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

int findLength(Node *head)
{
    int length = 0;
    while(head!=nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}
int findIntersection(Node *head1, Node *head2,int diff)
{
    Node *temp1 = head1, *temp2 = head2;
    for(int i=0;i<diff;i++)
    {
        temp1 = temp1->next;
    }
    while(temp1!=nullptr && temp2!=nullptr)
    {
        if(temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
int findNode(Node *head1,Node *head2)
{
    int length1 = findLength(head1);
    int length2 = findLength(head2);
    int diff=0;
    if(length1>length2){
        diff = length1 - length2;
        return findIntersection(head1,head2,diff);
    }
    else
    {
        diff = length2 - length1;
        return findIntersection(head2,head1,diff);
    }
}
// Another method
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *temp1 = headA, *temp2 = headB;
//         while(temp1!=temp2){
//             if(temp1==nullptr)
//                 temp1 = headB;
//             else
//                 temp1 = temp1->next;
//             if(temp2 == nullptr)
//                 temp2 = headA;
//             else
//                 temp2 = temp2->next;
//         }
//         return temp1;
//     }
// };

int main()
{
    LinkedList list1,list2;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);
    list1.insert(6);
    list1.insert(7);
    list1.insert(8);

    list2.insert(9);
    list2.insert(10);
    list2.insert(11);
    list2.insert(12);
    list2.tail->next = list1.head->next->next->next->next;
    cout<<"Intersection point: "<<findNode(list1.head,list2.head);
    return 0;
}