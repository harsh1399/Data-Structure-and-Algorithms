/* Binary tree is given and you need find vertical sum of the nodes that are in same vertical line in Time 
and Space Complexity O(n) */

#include<iostream>
#include "../HeaderFiles/BinarySearchTree.h"
#include<map>
using namespace std;

void verticalSum(Node* root, map<int,int> &nodeAtDist,int verticalDist)
{
    if(root==nullptr) return;
    verticalSum(root->left,nodeAtDist,verticalDist-1);
    map<int,int>::const_iterator got = nodeAtDist.find(verticalDist);
    if(got!=nodeAtDist.end())
    {
        int num1 = got->second;
        nodeAtDist[verticalDist] = num1+root->data;
    }
    else
    {
        nodeAtDist[verticalDist] = root->data;
    }
    verticalSum(root->right,nodeAtDist,verticalDist+1);
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
    map<int,int> nodeAtDist;
    verticalSum(root,nodeAtDist,0);
    for(auto i =nodeAtDist.begin();i!=nodeAtDist.end();i++)
    {
        cout<<i->second<<" ";
    }
    return 0;
}