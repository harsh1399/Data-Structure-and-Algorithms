/* Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at t he depth k + 1.*/

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<vector>
using namespace std;
class NodeDetails{
  public:
    int level;
    int parent;
    NodeDetails(int level,int parent)
    {
        this->level = level;
        this->parent = parent;
    }
};
void cousins(Node *root,int x,int y,Node *parent,int level,vector<NodeDetails> &nodes)
    {
        if(root == NULL)
            return;
        if(root->data == x || root->data ==y)
        {
            if(parent!=NULL)
            {
                NodeDetails node(level,parent->data);
                nodes.push_back(node);   
            }
            return;
        }
        cousins(root->left,x,y,root,level+1,nodes);
        cousins(root->right,x,y,root,level+1,nodes);
    }
    bool isCousins(Node* root, int x, int y) {
        vector<NodeDetails> nodes;
        cousins(root,x,y,NULL,0,nodes);
        if(nodes.size() == 1 || nodes.size() == 0)
            return false;
        NodeDetails node1 = nodes[0];
        NodeDetails node2 = nodes[1];
        if(node1.level == node2.level && node1.parent != node2.parent)
            return true;
        return false;
    }

int main()
{
    Node *root = new Node(1);
    root->left = new Node(4);
    root->left->left= new Node(13);
    root->left->right = new Node(12);
    root->left->right->left = new Node(16);

    root->right = new Node(25);
    root->right->right = new Node(32);
    root->right->right->right = new Node(22);
    root->right->right->left = new Node(26);

    cout<<"Is cousins: "<<isCousins(root,12,32);
}
 