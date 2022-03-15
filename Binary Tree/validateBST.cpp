/* Given the root of a binary tree, determine if it is a valid binary search tree (BST). */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;
bool isBST(Node* root, long long int max,long long int min)
{
    if(root==NULL)         
        return true;
    long long int val = root->data;
    bool left_bst = isBST(root->left,val-1,min);
    bool right_bst = isBST(root->right,max,val+1);
    if(root->data >= min && root->data <= max && left_bst && right_bst)
        return true;
    return false;
}
bool isValidBST(Node* root) {
    long long int max = INT_MAX;
    long long int min = INT_MIN;
    return isBST(root,max,min); 
}
int main()
{
    Node *root = new Node(12);
    root->left = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(9);

    root->right = new Node(25);
    root->right->left = new Node(16);
    root->right->right = new Node(24);

    cout<<"Is binary search tree:"<<isValidBST(root);
    return 0;
}