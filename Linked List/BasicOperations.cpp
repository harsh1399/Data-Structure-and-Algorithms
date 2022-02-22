/* Insert search delete operations on a linked list */
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
    public:
    Node *head = nullptr,*tail = nullptr;

    void insert(int data)
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
    bool search(int data)
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
    void print_list()
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<< temp->data<<" ";
            temp = temp->next;
        }
    }
    void delete_node(int data)
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
};
int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.print_list();
    cout<<endl;
    cout<<list.search(4)<<endl;
    cout<<list.search(5)<<endl;
    cout<<list.search(9)<<endl;  

    list.delete_node(3);
    list.delete_node(1);
    list.delete_node(5);

    list.print_list(); 
}