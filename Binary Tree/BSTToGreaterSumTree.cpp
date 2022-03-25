/* Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the 
original BST is changed to the original key plus the sum of all keys greater than the original key in BST. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

void sumTree(Node *root,int &max_sum)
{
    if(root==NULL)
        return;
    sumTree(root->right,max_sum);
    if(max_sum!=-1)
        root->data += max_sum;
    max_sum = root->data;
    sumTree(root->left,max_sum); 
}
Node* bstToGst(Node* root) {
    int sum = -1;
    sumTree(root,sum);
    return root;
}
int main()
{
    BST bst;
    bst.insert(4);
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);
    bst.insert(8);
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    bst.insert(3);

    preorder(bst.root);
    cout<<endl<<"Greater sum tree"<<endl;
    bstToGst(bst.root);
    preorder(bst.root);
    return 0;
}