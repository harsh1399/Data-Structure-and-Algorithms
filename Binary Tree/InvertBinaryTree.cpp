/* Given the root of a binary tree, invert the tree, and return its root. */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
using namespace std;

Node* invertTree(Node* root) {
    if(root == NULL)
        return NULL;
    Node *image_root = new Node(root->data);
    image_root->right = invertTree(root->left);
    image_root->left = invertTree(root->right);
    return image_root;
}

void invertBinaryTree(Node *root)
{
    if(root == NULL)
        return;
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    Node *newNode = invertTree(root);
    invertBinaryTree(root);
}