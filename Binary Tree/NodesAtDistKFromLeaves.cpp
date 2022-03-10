/* Given a Binary Tree and a positive integer k, print all nodes that are distance k from a leaf node k 
distance from a leaf means k levels higher than a leaf node. For example, if k is more than the height of 
the Binary Tree, then nothing should be printed. Expected time complexity is O(n) where n is the number 
nodes in the given Binary Tree */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<vector>
using namespace std;

void nodesDistKLeaves(Node *root,vector<int> nodes,vector<bool> &printed,int k)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr && nodes.size()- k>=0 && printed[nodes.size()-k]==false)
    {
        cout<<nodes[nodes.size()-k]<<" ";
        printed[nodes.size()-k] = true;
    }
    else
    {
        nodes.push_back(root->data);
        printed.push_back(false);
        nodesDistKLeaves(root->left,nodes,printed,k);
        nodesDistKLeaves(root->right,nodes,printed,k);
    }
}
int main()
{
    Node *root;
    root = new Node(3);
    root->left = new Node(8);
    root->left->left = new Node(11);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(12);
    root->right = new Node(9);
    root->right->right = new Node(3);
    vector<int> nodes;
    vector<bool> printed;
    nodesDistKLeaves(root,nodes,printed,2);
    return 0;
}