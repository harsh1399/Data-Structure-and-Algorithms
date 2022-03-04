#ifndef BinarySearchTree_H_
#define BinarySearchTree_H_

class Node
{
    public:
    int data;
    Node *right;
    Node *left;

    Node(int val): data(val),right(nullptr),left(nullptr){}
};
class BST
{
    public:
    Node *root = nullptr;

    bool insert(int data);
    bool search(int data);
    void inorder();
    void preorder();
    void postorder();
    void delete_node(int data);
};


#endif