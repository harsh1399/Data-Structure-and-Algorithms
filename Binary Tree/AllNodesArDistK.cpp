/* Given the root of a binary tree, the value of a target node target, and an integer k, return an array 
of the values of all nodes that have a distance k from the target node. */
#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<vector>
using namespace std;

void downNodes(Node* root, int k, vector<int> &result)
    {
        if(root == NULL)
            return;
        if(k == 0)
        {
            result.push_back(root->data);
            return;
        }
        downNodes(root->left,k-1,result);
        downNodes(root->right,k-1,result);
    }
    int nodesAtDistK(Node* root, Node* target, int k, vector<int> &result)
    {
        if(root == NULL)
            return -1;
        if(root->data == target->data)
        {
            downNodes(root,k,result);
            return 1;
        }
        int dleft = nodesAtDistK(root->left,target,k,result);
        if(dleft!=-1)
        {
            if(dleft == k)
                result.push_back(root->data);
            else
                downNodes(root->right,k-dleft-1,result);
            return 1+dleft;
        }
        int dright = nodesAtDistK(root->right,target,k,result);
        if(dright!=-1)
        {
            if(dright == k)
                result.push_back(root->data);
            else
                downNodes(root->left,k-dright-1,result);
            return 1+dright;
        }
        return -1;
    }
    vector<int> distanceK(Node* root, Node* target, int k) {
        vector<int> result;
        nodesAtDistK(root,target,k,result);
        return result;
    }

int main()
{
    Node *root,*target;
    target = new Node(5);
    root = new Node(1);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    vector<int> result = distanceK(root,target,2);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    return 0;
}