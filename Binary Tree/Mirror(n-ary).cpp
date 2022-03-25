/* Two n-ary trees given , Check if they are mirror of each other or not In Time and Space Complexity O(n)  */

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
void pushStack(Node *root,stack<int> &real_data)
{
    if(root == nullptr)
        return;
    real_data.push(root->data);
    for(int i=0;i<root->children.size();i++)
    {
        pushStack(root->children.at(i),real_data);
    }
}
void enQueue(Node *image_root , queue<int> &image_queue)
{
    if(image_root == nullptr)
        return;
    for(int i=0;i<image_root->children.size();i++)
    {
        enQueue(image_root->children.at(i),image_queue);
    }
    image_queue.push(image_root->data);
}
bool isSame(stack<int> &real_data, queue<int> &image_queue)
{
    for(int i=0;i<real_data.size();i++)
    {
        int stack_data = real_data.top();
        int queue_data = image_queue.front();
        real_data.pop(); image_queue.pop();
        if(stack_data!=queue_data)
            return false;
    }
    return true;
}
int main()
{
    Node *root = new Node(13);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));

    root->children.at(2)->children.push_back(new Node(1));
    root->children.at(3)->children.push_back(new Node(7));
    root->children.at(3)->children.push_back(new Node(8));
    root->children.at(3)->children.push_back(new Node(9));

    Node *image_root = new Node(13);
    root->children.push_back(new Node(100));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(2));

    root->children.at(2)->children.push_back(new Node(1));
    root->children.at(3)->children.push_back(new Node(9));
    root->children.at(3)->children.push_back(new Node(8));
    root->children.at(3)->children.push_back(new Node(7));

    stack<int> real_data;
    queue<int> image_queue;
    pushStack(root,real_data);
    enQueue(image_root,image_queue);
    cout<<"is both tree same:"<<isSame(real_data,image_queue);
}