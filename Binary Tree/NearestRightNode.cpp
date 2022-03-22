/* Given a Binary tree and a key in the binary tree, find the node right to the given key. If there is no 
node on right side, then return NULL. Expected time complexity is O(n) where n is the number of nodes in 
the given binary tree */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<queue>
using namespace std;

int nearestRightNode(Node *root,int data)
{
    if(root==nullptr)
        return -1;
    queue<Node*> nodes;
    nodes.push(root);
    int flag=0,size=0;
    while(!nodes.empty())
    {
        size = nodes.size();
        for(int i=0;i<size;i++)
        {
            Node *current = nodes.front();
            nodes.pop();
            if(current->data == data)
            {
                flag=1;
                break;
            }
            if(current->left!=nullptr) nodes.push(current->left);
            if(current->right!=nullptr) nodes.push(current->right);
        }
        if(flag==1)
        {
            if(nodes.size()==0)
                return -1;
            Node *nearestRight = nodes.front();
            nodes.pop();
            return nearestRight->data;
        }
    }
    return -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(13);
    root->left->right = new Node(12);
    
    root->right = new Node(25);
    root->right->right = new Node(32);
    root->right->right->right = new Node(22);
    root->right->right->left = new Node(26);

    cout<<"nearest right node: "<<nearestRightNode(root,12);
    return 0;
}