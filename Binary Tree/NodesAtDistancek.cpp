/* Print all the nodes which are at k distance from the root. Root of the Binary tree and K is given as 
Input in Time Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;
int count = 0;
void distanceKFromRoot(Node *root,int k)
{
    if(root == nullptr)
    {
        count--;
        return;
    }
    if(count==k)
    {
        cout<<root->data<<" ";
        count--;
        return;
    }
    count++;
    distanceKFromRoot(root->left,k);
    count++;
    distanceKFromRoot(root->right,k);
    count--;
}
int main()
{
    Node *root;
    int k;
    root = new Node(1);
    //left subtree
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->left->left = new Node(12);
    // right subtree
    root->right = new Node(23);
    root->right->right = new Node(32);
    root->right->right->left = new Node(22);
    root->right->right->right = new Node(10);

    distanceKFromRoot(root,3);
    return 0;
}