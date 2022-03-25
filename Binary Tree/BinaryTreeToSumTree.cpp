/* Given a Binary Tree, Convert this to a tree where each node contains the sum of the left and right sub 
trees in the original tree. The values of leaf nodes are changed to 0. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

int sumTree(Node *root)
{
    if(root==nullptr)
        return 0;
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    int temp = root->data;
    root->data = rightSum + leftSum;
    return (root->data)+temp;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(-3);
    root->left->left = new Node(9);
    root->left->right = new Node(-4);

    root->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(5);
    cout<<"preorder"<<endl;
    preorder(root);
    sumTree(root);
    cout<<endl<<"sumtree"<<endl;
    preorder(root);
    return 0;
}