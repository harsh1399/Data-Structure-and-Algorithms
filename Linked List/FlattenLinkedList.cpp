/* Linked list is given also, in addition to the next reference, each node has a child pointer that can 
point to a separate list. With the head node, flatten the list to a single-level linked list in Time 
Complexity O(n) */ //Flatten in sorted manner // list is sorted horizontally and vertically

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *down;
    node *next;
    node(int value)
    {
        this->data = value;
        this->down = nullptr;
        this->next = nullptr;    
    }
};
node* mergeLinkedList(node* head1, node *head2)
{
    node *merge_head,*fast,*slow,*second,*temp;
    if(head1->data > head2->data)
    {
        merge_head = head2;
        second = head1;
    }
    else
    {
        merge_head = head1;
        second = head2;
    }
    fast = merge_head->down;
    slow = merge_head;
    while(fast!=nullptr && second!=nullptr)
    {
        if(second->data > slow->data && second->data < fast->data)
        {
            temp = second->down;
            slow->down = second;
            second->down = fast;
            slow = slow->down;
            second = temp;
        }
        else
        {
            fast = fast->down;
            slow = slow->down;
        }
    }
    if(second!=nullptr)
        slow->down = second;
    return merge_head;
}
node *flatten_linkedlist(node *head)
{
    node *merge_head,*list1 = head,*list2 = head->next,*next_list = head->next->next;
    merge_head = mergeLinkedList(list1, list2);
    while(next_list!= nullptr)
    {
        merge_head = mergeLinkedList(merge_head,next_list);
        next_list = next_list->next;
    }
    return merge_head;
}
int main()
{
    node *head = new node(4);
    head->down = new node(6);
    head->down->down = new node(7);
    head->down->down->down = new node(30);

    head->next = new node(11);
    head->next->down = new node(20);

    head->next->next = new node(18);
    head->next->next->down = new node(22);
    head->next->next->down->down = new node(50);

    head->next->next->next= new node(28);
    head->next->next->next->down= new node(35);
    head->next->next->next->down->down= new node(40);
    head->next->next->next->down->down->down= new node(45);

    node *merge_head = flatten_linkedlist(head);
    node *temp = merge_head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->down;
    }
    return 0;
}