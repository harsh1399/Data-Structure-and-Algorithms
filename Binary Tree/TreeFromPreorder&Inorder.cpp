/*Construct a binary tree, given it's preorder and inorder traversal*/

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;
int searchRootInorder(int *inorder,int low,int high,int data)
{
    for(int i=low;i<=high;i++)
    {
        if(inorder[i] == data)
            return i;
    }
    return -1;
}
Node *constructTree(int *preorder, int *inorder, int pre_low,int pre_high, int in_low, int in_high)
{
    if(pre_low>pre_high)
        return nullptr;
    Node *root = new Node(preorder[pre_low]);
    int root_index_inorder = searchRootInorder(inorder,in_low,in_high,root->data);
    if(root_index_inorder == -1)
        return nullptr;
    int element_left = root_index_inorder - in_low;
    root->left = constructTree(preorder,inorder,pre_low+1,pre_low+element_left,in_low,in_low+element_left-1);
    root->right = constructTree(preorder,inorder,pre_low+element_left+1,pre_high,in_low+element_left+1,in_high);
    return root;
}

int main()
{
    int preorder[] = {1,2,3,4,6,7,5};
    int inorder[] = {3,2,6,4,7,1,5};
    Node *root = constructTree(preorder,inorder,0,6,0,6);
    cout<<"post order traversal:"<<endl;
    postorder(root);
}