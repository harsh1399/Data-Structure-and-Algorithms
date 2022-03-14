/* We have the inorder and postorder traversal sequence of a binary tree to generate the Binary tree */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;
int searchRoot(int *inorder,int low,int high,int element)
{
    for(int i=low;i<=high;i++)
    {
        if(inorder[i] == element)
            return i;
    }
    return -1;
}
Node* constructTree(int *postorder,int* inorder ,int low_post ,int high_post,int low_inorder,int high_inorder)
{
    if(low_post>high_post || low_inorder > high_inorder)
        return nullptr;
    Node *root = new Node(postorder[high_post]);
    int index = searchRoot(inorder,low_inorder,high_inorder,root->data);
    int elementsInRightSubtree = high_inorder - index;
    root->left = constructTree(postorder,inorder,low_post,high_post-elementsInRightSubtree-1,low_inorder,index-1);
    root->right = constructTree(postorder,inorder,high_post-elementsInRightSubtree,high_post-1,index+1,high_inorder);
    return root;
}
int main()
{
    int postorder[] = {8,4,5,2,6,7,3,1};
    int inorder[] = {4,8,2,5,1,6,3,7};
    Node* root = constructTree(postorder,inorder,0,7,0,7);
    return 0;
}