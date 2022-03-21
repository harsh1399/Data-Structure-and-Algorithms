/* Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a
file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree
is 'deserialization' in Time and Space Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<vector>
using namespace std;
int index_preorder = -1;
void serial(Node* root,vector<int> &preorder)
{
    if(root==NULL)
    {
        preorder.push_back(-1);
        return;
    }
    preorder.push_back(root->data);
    serial(root->left,preorder);
    serial(root->right,preorder);
}
    // Encodes a tree to a single string.
vector<int> serialize(Node* root) {
    vector<int> preorder;
    if(root == NULL)
        return preorder;
    serial(root,preorder);
    return preorder;
}
    // Decodes your encoded data to tree.
Node* deserialize(vector<int> preorder) {
    if(preorder.size()==0)
        return NULL;
    index_preorder++;
    if(preorder[index_preorder]==-1)
    {
        return NULL;
    }
    Node *node = new Node(preorder[index_preorder]);
    node->left = deserialize(preorder);
    node->right = deserialize(preorder);
    return node;
}
int main()
{
    Node *root = new Node(1);
    /* root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 */
    vector<int> preorder = serialize(root);
    Node *new_root = deserialize(preorder);
    return 0;
}