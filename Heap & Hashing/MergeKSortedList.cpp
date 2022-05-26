// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comparator{
  public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *merged = new ListNode();
        ListNode *temp = merged;
        priority_queue<ListNode*,vector<ListNode*>,comparator> minheap;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
                minheap.push(lists[i]);
        }
        while(!minheap.empty())
        {
            ListNode *node = minheap.top();
            temp->next = node;
            minheap.pop();
            temp = temp->next;
            if(node->next)
                minheap.push(node->next);
        }
        return merged->next;   
    }
};

int main(){
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);
    //list1->next->next = new ListNode(5);

    vector<ListNode*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    Solution s;
    ListNode *merged = s.mergeKLists(lists);
    return 0;
}