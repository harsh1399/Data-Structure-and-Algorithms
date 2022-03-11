/* Print all the boundary nodes in the binary tree.Boundary includes left boundary, leaves, and right 
boundary in anti clockwise direction in O(n) Time Complexity */
#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

void leftInternalNodes(Node* root)
{
    if(root != nullptr)
    {
        if(root->left != nullptr)
        {
            cout<<root->data<<" ";
            leftInternalNodes(root->left);
        }
        else if(root->right!=nullptr)
        {
            cout<<root->data<<" ";
            leftInternalNodes(root->right);
        }
    }
}

void rightInternalNodes(Node* root)
{
    if(root != nullptr)
    {
        if(root->right!=nullptr)
        {
            rightInternalNodes(root->right);
            cout<<root->data<<" ";
        }
        else if(root->left != nullptr)
        {
            rightInternalNodes(root->left);
            cout<<root->data<<" ";
        }
    }
}

void leaveNodes(Node *root)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
    {
        cout<<root->data<<" ";
        return;
    }
    leaveNodes(root->left);
    leaveNodes(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->right = new Node(16);
    root->right->right = new Node(7);
    root->right->right->left = new Node(17);

    cout<<root->data<<" ";
    leftInternalNodes(root->left);
    leaveNodes(root);
    rightInternalNodes(root->right);
    return 0;
}