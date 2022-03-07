/* Convert BT to DLL such that the left pointer of the node should be pointing to the previous node in the 
doubly linked list, and the right pointer should be pointing to the next node in the doubly linked list 
in Time Complexity O(n) and Space O(Height) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

void convertBT2DLL(Node *root, Node **head)
{
    if(root ==nullptr)
        return;
    static Node *prev = nullptr;
    convertBT2DLL(root->left , head);
    if(prev == nullptr)
        *head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    convertBT2DLL(root->right,head);
}
int main()
{
    Node *root,*head;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);

    convertBT2DLL(root,&head);
    cout<<"Doubly linked list:"<<endl;
    Node *temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}