/* Find the distance between two keys in a binary tree, no parent pointers are given. 
Distance between two nodes is the minimum number of edges to be traversed to reach one node from other. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

Node* lowestCommonAncestor(Node *root, int data1, int data2)
{
    if(root == nullptr)
        return nullptr;
    Node *itself = nullptr;
    if(root->data == data1 || root->data == data2)
        itself = root;
    Node *nodeLeft = lowestCommonAncestor(root->left,data1,data2);
    Node *nodeRight = lowestCommonAncestor(root->right,data1,data2);
    if((itself != nullptr && nodeLeft!= nullptr) || (itself != nullptr && nodeRight!= nullptr) || (nodeRight != nullptr && nodeLeft!= nullptr))
        return root;
    if(nodeLeft!=nullptr) return nodeLeft;
    if(nodeRight!=nullptr) return nodeRight;
    if(itself!=nullptr) return itself;
    return nullptr;
}
bool distance(Node *root,int data, int *dist,int k)
{
    if(root == nullptr)
        return false;
    if(root->data == data)
    {
        *dist = k;
        return true;
    }
    if(distance(root->left, data,dist,k+1))
        return true;
    if(distance(root->right,data,dist,k+1))
        return true;
    return false;
}
void minDistance(Node *root, int data1, int data2)
{
    Node *LCA = lowestCommonAncestor(root,data1,data2);
    int dist1=0,dist2=0;
    cout<<"Lowest Common Ancestor: "<<LCA->data<<endl;
    distance(LCA,data1,&dist1,0);
    distance(LCA,data2,&dist2,0);
    cout<<"min distance: "<< dist1+dist2<<endl;
}
int main()
{
    Node *root = new Node(12);
    root->left = new Node(4);
    root->left->left = new Node(13);
    root->left->left->left = new Node(2);
    root->left->right = new Node(9);
    root->left->right->left = new Node(26);
    root->left->right->right = new Node(22);

    root->right = new Node(25);
    root->right->right = new Node(32);
    root->right->left = new Node(16);

    minDistance(root, 2,26);
    return 0;
}