/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
 p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a 
 descendant of itself).” */

 #include<iostream>
 #include "../HeaderFiles/BinarySearchTree.h"
 using namespace std;

 Node* lowestCommonAncestor(Node* root, int data1, int data2)
 {
    Node* itself=nullptr;
    if(root == NULL)
        return nullptr;
    if(root->data == data1 || root->data == data2)
        itself = root;
    Node* nodeLeft = lowestCommonAncestor(root->left, data1,data2);
    Node* nodeRight = lowestCommonAncestor(root->right,data1,data2);
    if((nodeLeft!=nullptr && nodeRight!=nullptr) || (itself!=nullptr && nodeRight!=nullptr) || (itself!=nullptr && nodeLeft!=nullptr))
    {
        return root;
    }
    if(itself!=nullptr) return itself;
    if(nodeLeft!=nullptr)return nodeLeft;
    if(nodeRight!=nullptr) return nodeRight;
    return nullptr;
 }
 int main()
 {
     Node *root = new Node(3);
     root->left = new Node(5);
     root->left->left = new Node(6);
     root->left->right = new Node(2);
     root->left->right->left = new Node(7);
     root->left->right->right = new Node(4);

     root->right = new Node(1);
     root->right->right = new Node(0);
     root->right->left = new Node(8);
     Node *result = lowestCommonAncestor(root,6,2);
     cout<<result->data;
     return 0;
 }