/* Algorithm to Connect all the nodes in same level of a binary tree in Constant Space and O(n) Time Compelxity */

#include<iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left,*right,*next;
    
    TreeNode(int data)  
    {
        val = data;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
TreeNode *findNode(TreeNode *temp=nullptr)
{
    while(temp!=nullptr)
    {
        if(temp->left!=nullptr)
        {
            return temp->left;
        }
        else if(temp->right!=nullptr)
        {
            return temp->right;
        }
        temp = temp->next;
    }
    return temp;
}
void connectNodes(TreeNode *root)
{
    if(root == NULL || (root->left==nullptr && root->right==nullptr)) return;
    if(root->left!=nullptr && root->right!=nullptr)
    {
        root->left->next = root->right;
        if(root->next!=nullptr)
        {
            root->right->next = findNode(root->next);
        }    
    }
    else if((root->left!=nullptr || root->right!=nullptr) && root->next!=nullptr)
    {
        if(root->left!=nullptr)
            root->left->next = findNode(root->next);
        else if(root->right!=nullptr)
            root->right->next = findNode(root->next);
    }
    connectNodes(root->right);
    connectNodes(root->left);
}
int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(13);
    root->left->left->left = new TreeNode(9);

    root->right = new TreeNode(10);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(15);
    root->right->right->right = new TreeNode(20);

    connectNodes(root);
    return 0;
}