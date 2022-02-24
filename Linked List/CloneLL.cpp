/* You are given a double Link List with one reference of each node pointing to the next node just like in 
a single link list. The second reference however can point to any node in the list and not just the 
previous node.Write a program in O(n) time which will create a copy of this list  */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* random;
    node(int value)
    {
        this->data = value;
        this->next = nullptr;
        this->random = nullptr;
    }
};
node* clone(node* head)
{
    if(head == nullptr)
        return head;
    node* temp = head,*temp1,*head_clone=nullptr,*temp2;
    while(temp!=nullptr)
    {
        node* new_node = new node(temp->data);
        if(head_clone == nullptr)
        {
            head_clone = new_node;
            temp2 = head_clone;
        }
        else
        {
            temp2->next = new_node;
            temp2 = temp2->next;
        }
        temp1 = temp->next;
        temp->next = new_node;
        new_node->random = temp;
        temp = temp1;
    }
    temp2 = head_clone;
    while(temp2!=nullptr)
    {
        temp2->random = temp2->random->random->next;
        temp2 = temp2->next;
    }
    return head_clone;
}
int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    
    //assign random
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    node *clone_head = clone(head);

}