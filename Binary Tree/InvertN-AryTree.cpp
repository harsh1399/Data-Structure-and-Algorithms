/* Given a root of of n-ary tree, invert the tree */

#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    vector<Node*> children;
    Node(int val)
    {
        data = val;
    }
};
void reverse(Node *root);
void invertNAry(Node *root)
{
    if(root == nullptr)
        return;
    if(root->children.size()>0)
        reverse(root);
    for(int i=0;i<root->children.size();i++)
    {
        invertNAry(root->children.at(i));
    }
}
void reverse(Node *root)
{
    int i=0,j = root->children.size()-1;
    while(i<j)
    {
        Node *temp = root->children.at(i);
        root->children.at(i)  = root->children.at(j);
        root->children.at(j) = temp;
        i++;j--;
    }
}
void preorder(Node *root)
{
	cout<<root->data<<" ";
	for (int i = 0; i < root->children.size(); i++) 
        preorder(root->children.at(i));	        
    
}
int main()
{
    Node *root = new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));

    root->children.at(2)->children.push_back(new Node(1));
    root->children.at(3)->children.push_back(new Node(7));
    root->children.at(3)->children.push_back(new Node(8));
    root->children.at(3)->children.push_back(new Node(9));
    cout<<"Before invert: "<<endl;
    preorder(root);
    invertNAry(root);
    cout<<"After invert: "<<endl;
    preorder(root);
    return 0;
}