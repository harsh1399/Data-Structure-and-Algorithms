#ifndef linkedList_H_
#define linkedList_H_

class Node
{
    public:
    int data;
    Node *next;

    Node(int val): data(val),next(nullptr){}
};
class LinkedList
{
    public:
    Node *head = nullptr,*tail = nullptr;

    void insert(int data);
    bool search(int data);
    void print_list();
    void delete_node(int data);
};


#endif