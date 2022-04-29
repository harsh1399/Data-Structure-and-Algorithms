// Given a binary tree root and a linked list with head as the first node. 

// Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

// In this context downward path means a path that starts at some node and goes downwards.

#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
bool isPresent(ListNode *current, TreeNode *root)
    {
        if(root==nullptr){
            return false;
        }   
        if(root->val == current->val)
        {
            if(current->next == nullptr)
                return true;
            if(isPresent(current->next,root->left)) return true;
            if(isPresent(current->next,root->right)) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr)
            return false;
        if(head->val == root->val)
        {
            if(isPresent(head,root)) return true;
        }
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }

int main()
{
    TreeNode root(2);
    root.right = new TreeNode(2);
    root.right->right = new TreeNode(2);
    root.right->right->right = new TreeNode(1);

    ListNode head(2);
    head.next = new ListNode(2);
    head.next->next = new ListNode(1);

    cout<<"is linked list present? "<<isSubPath(&head,&root);

}