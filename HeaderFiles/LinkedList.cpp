#include<iostream>
#include "LinkedList.h"

void LinkedList :: insert(int data)
{
    Node *newnode = new Node(data);
    if(head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }        
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
void LinkedList :: print_list()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        std::cout<< temp->data<<" ";
        temp = temp->next;
    }
}
    bool LinkedList :: search(int data)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            if(temp->data == data)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void LinkedList :: delete_node(int data)
    {
        Node *fast = head;
        Node *slow = nullptr;
        if(fast->data == data)
        {
            head = fast->next;
            delete(fast);
            return;
        }
        fast = fast->next;
        slow = head;
        while(fast!=NULL)
        {
            if(fast->data == data)
            {
                slow->next = fast->next;
                if(fast->next == nullptr)
                    tail = slow;
                fast->next = nullptr;
                delete(fast);
                return;
            }
            slow = fast;
            fast = fast->next;
        }
    }
    
    
