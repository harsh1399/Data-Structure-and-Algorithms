/*Check if the binary tree is balanced or not*/

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<cstdlib>
using namespace std;

int checkBalancedTree(Node *root)
{
    if(root ==nullptr)
        return 0;
    int leftSubtreeHeight = checkBalancedTree(root->left);
    int rightSubtreeHeight = checkBalancedTree(root->right);
    int heightDiff = abs(leftSubtreeHeight - rightSubtreeHeight);
    if(heightDiff>1 || leftSubtreeHeight == -1 || rightSubtreeHeight==-1)
        return -1;
    int maxHeight = (leftSubtreeHeight > rightSubtreeHeight)?leftSubtreeHeight:rightSubtreeHeight;
    return maxHeight+1;
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //root->left->right->left = new Node(6);
    //root->left->right->left->right = new Node(8);
    root->right = new Node(3);

    if(checkBalancedTree(root)==-1)
        cout<<"Tree is not balanced"<<endl;
    else
        cout<<"Tree is balanced"<<endl;
    return 0;
}