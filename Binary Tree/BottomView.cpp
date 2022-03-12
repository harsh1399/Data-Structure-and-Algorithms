/* Given a binary tree, print the values of nodes which would be present in bottom of view of binary tree  */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<unordered_map>
using namespace std;
class NodeData
{
    public:
    int data;
    int level;
    NodeData(int data,int level)
    {
        this->data = data;
        this->level = level;
    }
    NodeData(){}
};
void bottomView(Node *root,int horizontalDist,int level,unordered_map<int,NodeData> &nodeDetails)
{
    if(root==nullptr)
        return;
    unordered_map<int,NodeData>::const_iterator got = nodeDetails.find(horizontalDist);
    NodeData nodedata(root->data,level);
    if(got != nodeDetails.end())
    {
        NodeData presentNode = got->second;
        if(presentNode.level<level)
        {
            nodeDetails[horizontalDist] = nodedata;
        }
    }
    else
    {
        nodeDetails[horizontalDist] = nodedata;
    }
    bottomView(root->left,horizontalDist-1,level+1,nodeDetails);
    bottomView(root->right,horizontalDist+1,level+1,nodeDetails);
}
int main()
{
    Node *root = new Node(13);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->left->right->left = new Node(11);
    
    root->right = new Node(18);
    root->right->right = new Node(20);
    root->right->right->left = new Node(22);
    unordered_map<int,NodeData> nodeDetails;
    bottomView(root,0,0,nodeDetails);
    return 0;
}