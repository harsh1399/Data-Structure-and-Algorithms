#include<iostream>
#include "BinarySearchTree.h"

bool BST:: insert(int data)   //insert new data, no duplicate allowed
{
    Node *new_node = new Node(data);
    if(root == nullptr)
    {
        root = new_node;
    }
    else{
        Node *parent,*temp = root;
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
        return true;
    }
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
