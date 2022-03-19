/* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between). */

#include<iostream>
#include<vector>
#include<stack>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

vector<vector<int>> zigzagTraversal(Node *root)
{
    vector<vector<int>> result;
    if(root==nullptr)
        return result;
    vector<int> traversal;
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        traversal.clear();
        while(!s1.empty())
        {
            Node* current = s1.top();
            s1.pop();
            traversal.push_back(current->data);
            if(current->left!=nullptr) s2.push(current->left);
            if(current->right!=nullptr) s2.push(current->right);
        }
        result.push_back(traversal);
        traversal.clear();
        while(!s2.empty())
        {
            Node *current = s2.top();
            s2.pop();
            traversal.push_back(current->data);
            if(current->right!=nullptr) s1.push(current->right);
            if(current->left!=nullptr) s1.push(current->left);
        }
        if(!traversal.empty())
            result.push_back(traversal);
    }
    return result;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    vector<vector<int>> result = zigzagTraversal(root);
    return 0;
}