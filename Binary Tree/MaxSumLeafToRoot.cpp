/* Find the maximum sum leaf to root path in a Binary Tree. Means in all the paths from root to leaves, 
find the path which has the maximum sum */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<algorithm>
using namespace std;

int maxSum(Node *root)
{
    if(root==nullptr) return 0;
    int leftSum = maxSum(root->left);
    int rightSum = maxSum(root->right);
    return max(root->data+leftSum, root->data+rightSum);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(5);

    root->right = new Node(10);
    root->right->left = new Node(8);
    root->right->right = new Node(12);
    cout<<"max sum from root to leaf: "<<maxSum(root);
    return 0;
}