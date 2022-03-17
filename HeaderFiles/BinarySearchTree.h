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
    Node* Maximum();
    Node *Minimum();
    void delete_node(int data);
};

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void levelorder(Node *root);
void preorder_iterative(Node *root);
#endif