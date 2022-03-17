/* Algorithm to print Binary Tree nodes level by level in reverse order. It means all the nodes at the last 
level should be printed first followed by the nodes of second last level and so on in Time Complexity O(n) and Space Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<queue>
#include<stack>
using namespace std;

void reverseLevelOrder(Node *root)
{
    if(root==nullptr)
        return;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        s.push(current);
        if(current->right!=nullptr) q.push(current->right);
        if(current->left!=nullptr) q.push(current->left);
        q.pop();
    }
    while(!s.empty())
    {
        Node *current = s.top();
        cout<<current->data<<" ";
        s.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    reverseLevelOrder(root);
    return 0;
}