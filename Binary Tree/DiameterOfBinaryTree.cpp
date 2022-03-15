/* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;
int diameter(Node* root, int *dia)
{
    if(root == NULL)
        return 0;
    int lh = diameter(root->left,dia);
    int rh = diameter(root->right,dia);
    if(lh+rh>*dia)
        *dia = lh+rh;
    int max_height = (lh>=rh)?lh:rh;
    return max_height+1;
}
int diameterOfBinaryTree(Node* root) {
    int dia = INT_MIN;
    diameter(root,&dia);
    return dia;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    cout<<"Diameter of binary tree : "<<diameterOfBinaryTree(root);
    return 0;
}