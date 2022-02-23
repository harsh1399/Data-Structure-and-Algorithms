/* Given a singly linked list, determine if it is a palindrome. */

#include<iostream>
#include "../HeaderFiles/LinkedList.h"
using namespace std;

bool checkPalindrome(LinkedList list)
{
    Node *prev,*current,*middle,*fast;
    prev = nullptr;
    current = list.head;
    middle = list.head;
    fast = list.head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        middle = middle->next;
        fast = fast->next->next;
        current->next = prev;
        prev = current;
        current = middle;
    }
    if(fast!=nullptr)
        current = current->next;
    while(prev!=nullptr && current!= nullptr)
    {
        if(prev->data!=current->data)
            return false;
        prev = prev->next;
        current = current->next;
    }
    return true;
}
int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    // list.insert(3);
    // list.insert(2);
    // list.insert(1);

    cout<<"Is palindrome or not: "<<checkPalindrome(list);
    return 0;
}