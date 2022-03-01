/* Rearrange a Single Linked List in Time Complexity O(n) and Space Complexity O(1) such one node selected 
from start next node from end  */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

Node* reverse(Node *head)
{
    Node *prev = nullptr,*current = head,*next = head;
    while(current!=nullptr)
    {
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *findMiddle(Node *head)
{
    Node *slow = head,*fast = head,*temp;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == nullptr)
    {
        temp->next = nullptr;
        return slow;
    }
    temp = slow->next;
    slow->next = nullptr;
    return temp;
}
void rearrange(Node *head)
{
    Node *middle = findMiddle(head);
    Node *head_list2 = reverse(middle);
    Node *slow = head,*fast = head->next,*second = head_list2,*temp;
    while(fast!=nullptr && second!=nullptr)
    {
        slow->next = second;
        temp = second->next;
        second->next = fast;
        second = temp;
        slow = fast;
        fast = fast->next;
    }
    if(second!=nullptr)
        slow->next = second;
}
int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    /* list.insert(4);
    list.insert(5);
    list.insert(6); */
    rearrange(list.head);
    list.print_list();
}