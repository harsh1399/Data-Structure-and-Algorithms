/* Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where the largest 
means subtree with the largest number of nodes in it. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

class NodeDetails{
    public:
    int size;
    bool isBST;
    int max;
    int min;
    int ans;
    NodeDetails(){}
    NodeDetails(int size,bool isBST, int max,int min)
    {
        this->size = size;
        this->isBST = isBST;
        this->max = max;
        this->min = min;
    }
};
NodeDetails largestBST(Node* root)
{
    if(root==nullptr)
        return NodeDetails(0,true,INT_MAX,INT_MIN);
    if(root->left == nullptr && root->right ==nullptr)
        return NodeDetails(1,true,root->data,root->data);
    
    NodeDetails leftSubtree = largestBST(root->left);
    NodeDetails rightSubtree = largestBST(root->right);
    NodeDetails detail;
    detail.size = leftSubtree.size + rightSubtree.size +1;
    if(root->data > leftSubtree.max && root->data<rightSubtree.min && leftSubtree.isBST && rightSubtree.isBST)
    {
        detail.min = min(leftSubtree.min,min(rightSubtree.min,root->data));
        detail.max = max(rightSubtree.max,max(leftSubtree.max,root->data));
        detail.isBST = true;
        detail.ans = detail.size;
        return detail;
    }
    detail.ans = max(leftSubtree.ans,rightSubtree.ans);
    detail.isBST = false;
    return detail;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(7);
 
    root->right = new Node(60);
    root->right->right = new Node(70);
    root->right->left = new Node(45);
    root->right->right->right = new Node(80);
    root->right->right->left = new Node(65);
 
    NodeDetails detail  = largestBST(root);
    cout<<"Largest BST: " << detail.ans;
    return 0;
}