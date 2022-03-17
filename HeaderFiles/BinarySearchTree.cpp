#include<iostream>
#include "BinarySearchTree.h"
#include<queue>
#include<stack>
bool BST:: insert(int data)   //insert new data, no duplicate allowed
{
    Node *new_node = new Node(data);
    Node *parent,*temp = root;
    if(root == nullptr)
    {
        root = new_node;
    }
    else{
        while(temp!=nullptr)
        {
            if(temp->data == data)
                return false;
            else if(temp->data < data)
            {
                parent = temp;
                temp = temp->right;
            }   
            else
            {
                parent = temp;
                temp = temp->left;
            }
        }
        if(parent->data > data)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return true;
}
bool BST:: search(int data)
{
    if(root == nullptr)
        return false;
    else
    {
        Node *temp = root;
        while(temp != nullptr)
        {
            if(temp->data == data)
                return true;
            else if(temp->data > data)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    return false;
}
Node* BST :: Maximum()
{
    Node *temp = root;
    while(temp->right!=nullptr)
        temp = temp->right;
    return temp;
}
Node* BST :: Minimum()
{
    Node *temp = root;
    while(temp->left!=nullptr)
        temp = temp->left;
    return temp;
}
void BST :: delete_node(int data)
{

}
void inorder(Node *root)
{
    if(root == nullptr)
        return;
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}
void preorder(Node *root)
{
    if(root == nullptr)
        return;
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void levelorder(Node *root)
{
    if(root==nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        std::cout<<current->data<<" ";
        if(current->left!=nullptr) q.push(current->left);
        if(current->right!=nullptr) q.push(current->right);
        q.pop();
    }
}
void preorder_iterative(Node *root)
{
    std::stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node *current = stk.top();
        stk.pop();
        std::cout<<current->data<<" ";
        if(current->right!=nullptr) stk.push(current->right);
        if(current->left!=nullptr) stk.push(current->left);
    }
}