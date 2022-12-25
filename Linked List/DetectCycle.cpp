// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *fast = head,*slow = head;
        while(fast!=nullptr)
        {
            if(fast->next == nullptr){
                fast = nullptr;
            }
            else{
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                    break;
            }
        }
        if(fast == nullptr){
            return nullptr;
        }
        slow = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

