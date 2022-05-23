
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    Node *prev,*next;
    int key,value;
    Node(int key,int value){
        prev = nullptr;
        next = nullptr;
        this->key = key;
        this->value = value;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> cache;
    int max_count;
    Node *front,*rear;
    LRUCache(int capacity) {
        this->max_count = capacity;
        front = nullptr;
        rear = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key)!= cache.end()){
            Node *temp = cache[key];
            if(front == rear){
                return temp->value;    
            }
            else if(temp == rear)
                return temp->value;
            else if(temp==front){
                front = front->next;
                temp->next->prev = nullptr;
                temp->next = nullptr;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = nullptr;
                temp->prev = nullptr;
            }
            rear->next = temp;
            temp->prev = rear;
            rear = rear->next;
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end())
        {
            get(key);
            cache[key]->value = value;
        }
        else if(max_count>0){
            if(front == nullptr && rear == nullptr){
                Node *newnode = new Node(key,value);
                front = newnode;
                rear = newnode;
                max_count--;
                cache[key] = newnode;
            }
            else{
                Node *newnode = new Node(key,value);
                rear->next = newnode;
                newnode->prev = rear;
                rear = rear->next;
                max_count--;
                cache[key] = newnode;
            }
        }
        else{
                Node *newnode = new Node(key,value);
                int deletekey = front->key;
                if(front == rear){
                    front = newnode; 
                    rear = newnode;
                    cache.erase(deletekey);
                    cache[key] = newnode; 
                }
                else{
                    front = front->next;
                    front->prev = nullptr;
                    rear->next = newnode;
                    newnode->prev = rear;
                    rear = rear->next;
                    //delete temp;
                    cache.erase(deletekey);
                    cache[key] = newnode;    
                }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1)<<endl;
    obj.put(3,3);
    cout<<obj.get(2)<<endl;
    obj.put(4,4);
    cout<<obj.get(1)<<endl;
    cout<<obj.get(3)<<endl;
    cout<<obj.get(4)<<endl;
}