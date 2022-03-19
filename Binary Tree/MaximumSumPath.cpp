/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<vector>
#include<algorithm>
using namespace std;
int maxSum(Node* root, vector<int> &maxSumList)
    {
        if(root==NULL)
            return 0;
        int leftSum = maxSum(root->left,maxSumList);
        int rightSum = maxSum(root->right,maxSumList);
        int sumAtNode = max({root->data,root->data+leftSum,root->data+rightSum,root->data+leftSum+rightSum});
        maxSumList.push_back(sumAtNode);
        return max({root->data+leftSum,root->data+rightSum,root->data});
    }
    int maxPathSum(Node* root) {
        vector<int> maxSumList;
        maxSum(root,maxSumList);
        return *max_element(maxSumList.begin(),maxSumList.end());
    }

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->right = new Node(7);
    root->right->left = new Node(15);
    cout<<"Max path sum: "<<maxPathSum(root);
    return 0; 
}