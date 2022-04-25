// Given the root of a binary tree, flatten the tree into a "linked list":

/*The "linked list" should use the same TreeNode class where the right child pointer points 
to the next node in the list and the left child pointer is always null.*/
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

Node* prev_node=nullptr;
void flatten(Node* root) {
    if(root==nullptr)
        return;
    //static TreeNode* prev;
    prev_node = root;
    flatten(root->left);
    Node* rightnode = root->right;
    if(root->left!=nullptr)
    {
        root->right = root->left;
        root->left = nullptr;
        prev_node->right = rightnode;
    }
    flatten(rightnode);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);

    flatten(root);
    return 0;
}