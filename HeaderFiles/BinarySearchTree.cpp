#include<iostream>
#include "BinarySearchTree.h"
#include<queue>
#include<stack>
bool BST:: insert(int data)   //insert new data, no duplicate allowed
{
    Node *new_node = new Node(data);
    Node *parent,*temp = root;
    if(root == nullptr)
    {
        root = new_node;
    }
    else{
        while(temp!=nullptr)
        {
            if(temp->data == data)
                return false;
            else if(temp->data < data)
            {
                parent = temp;
                temp = temp->right;
            }   
            else
            {
                parent = temp;
                temp = temp->left;
            }
        }
        if(parent->data > data)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return true;
}
bool BST:: search(int data)
{
    if(root == nullptr)
        return false;
    else
    {
        Node *temp = root;
        while(temp != nullptr)
        {
            if(temp->data == data)
                return true;
            else if(temp->data > data)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    return false;
}
Node* BST :: Maximum()
{
    Node *temp = root;
    while(temp->right!=nullptr)
        temp = temp->right;
    return temp;
}
Node* BST :: Minimum()
{
    Node *temp = root;
    while(temp->left!=nullptr)
        temp = temp->left;
    return temp;
}

void inorder(Node *root)
{
    if(root == nullptr)
        return;
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}
void preorder(Node *root)
{
    if(root == nullptr)
        return;
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void levelorder(Node *root)
{
    if(root==nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        std::cout<<current->data<<" ";
        if(current->left!=nullptr) q.push(current->left);
        if(current->right!=nullptr) q.push(current->right);
        q.pop();
    }
}
void preorder_iterative(Node *root)
{
    std::stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node *current = stk.top();
        stk.pop();
        std::cout<<current->data<<" ";
        if(current->right!=nullptr) stk.push(current->right);
        if(current->left!=nullptr) stk.push(current->left);
    }
}
void inorder_iterative(Node* root)
{
    std::stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node *current= stk.top();
        if(current->left!=nullptr)
        {
            stk.push(current->left);
            current->left = nullptr;
            continue;
        }
        else
        {
            std:: cout<< current->data<<" ";
            stk.pop();
            if(current->right!=nullptr)
                stk.push(current->right);
        }
    }
}
void inorder_iterative_1(Node* root)
{
    std::stack<Node *> stk;
    Node *current = root;
    while(current!=nullptr || !stk.empty())
    {
        while(current!=nullptr)
        {
            stk.push(current);
            current = current->left;
        }       
        current = stk.top();
        stk.pop();
        std::cout<<current->data<<" ";
        current = current->right;
    }
}

void searchNode(Node* &delet, Node* &parent,int key)
    {
        while(delet!=nullptr && delet->data!=key)
        {
            parent = delet;
            if(delet->data>key)
                delet = delet->left;
            else
                delet = delet->right;
        }
    }
    Node* predecessor(Node *root,Node* &predec_parent)
    {
        Node *temp = root->left;
        predec_parent = root;
        while(temp->right!=nullptr)
        {
            predec_parent = temp;
            temp = temp->right;
        }
        return temp;
    }
    void noChild(Node *delet, Node *parent)
    {
        if(parent->right == delet)
            parent->right = nullptr;
        else
            parent->left = nullptr;
    }
    void oneChild(Node *delet, Node *parent)
    {
        if(parent->right== delet)
        {
            if(delet->left == nullptr && delet->right != nullptr)
                parent->right = delet->right;
            else
                parent->right = delet->left;            
        }
        else
        {
            if(delet->left == nullptr && delet->right != nullptr)
                parent->left = delet->right;
            else
                parent->left = delet->left;          
        }
    }
    Node* deleteNode(Node* root, int key) {
        Node *parent = nullptr, *delet = root;
        searchNode(delet,parent,key);
        if(delet!=nullptr){
            if(delet->left == nullptr && delet->right == nullptr)
            {
                if(parent == nullptr)
                    return nullptr;
                noChild(delet,parent);
            }
            else if((delet->left == nullptr && delet->right != nullptr) || (delet->left != nullptr && delet->right == nullptr) )
            {
                if(parent == nullptr)
                {
                    if(root->left!=nullptr) return root->left;
                    return root->right;
                }
                oneChild(delet,parent);
            }
            else
            {
                Node *predec_parent=nullptr;
                Node *predec = predecessor(delet,predec_parent);
                if(predec->right == nullptr && predec->left == nullptr)
                    noChild(predec,predec_parent);
                else if((predec->left == nullptr && predec->right != nullptr) || (predec->left != nullptr && predec->right == nullptr))
                    oneChild(predec,predec_parent);
            
                predec->left = delet->left;
                predec->right = delet->right;
                if(parent == nullptr)
                {
                    root = predec;
                }
                else{
                    if(parent->left == delet)
                        parent->left = predec;
                    else
                        parent->right = predec;
                }
            }
        }
        return root;
    }