/* Printing the left view of a binary tree involves printing the left-most node, at each level, in the 
binary tree In Time Complexity O(n) and Space Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<unordered_map>
using namespace std;

void leftView(Node* root, int level, unordered_map<int,Node*> &NodeAtLevel)
{
    if(root == nullptr)
        return;
    unordered_map<int,Node*>::const_iterator got = NodeAtLevel.find(level);
    if(got==NodeAtLevel.end())
    {
        NodeAtLevel[level] = root;
    }
    leftView(root->left,level+1,NodeAtLevel);
    leftView(root->right,level+1,NodeAtLevel);
}
int main()
{
    Node *root = new Node(13);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->left->left->right = new Node(11);
    root->left->left->right->left = new Node(22);
    root->left->left->right->right = new Node(24);

    root->right = new Node(18);
    root->right->right = new Node(20);
    unordered_map<int,Node*> NodeAtLevel;
    leftView(root,0,NodeAtLevel);
    unordered_map<int,Node*>::iterator it = NodeAtLevel.begin();
    for(auto& it: NodeAtLevel)
    {
        cout<<it.first<<" "<<it.second->data<<endl;
    }
    return 0;
}