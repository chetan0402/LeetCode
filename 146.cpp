#include<unordered_map>
using namespace std;

struct Node{
    int val;
    int key;
    Node*next=nullptr;
    Node*prev=nullptr;
    Node(){}
    Node(int k,int v){
        key=k;
        val=v;
    };
};

class LRUCache {
    unordered_map<int,Node*> keyToNode;
    Node*oldest;
    Node*newest;
    int len=0;
    int limit;

    void removeNode(Node*cur){
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        cur->next=nullptr;
        cur->prev=nullptr;
        keyToNode.erase(cur->key);
    }

    void addNode(Node*cur){
        cur->next=newest;
        cur->prev=newest->prev;
        cur->prev->next=cur;
        newest->prev=cur;
        keyToNode[cur->key]=cur;
    }
public:
    LRUCache(int capacity) {
        oldest=new Node();
        newest=new Node();
        oldest->next=newest;
        newest->prev=oldest;
        limit=capacity;
    }
    
    int get(int key) {
        if(keyToNode.count(key)){
            auto curNode=keyToNode[key];
            removeNode(curNode);
            addNode(curNode);
            return curNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyToNode.count(key)){
            auto curNode=keyToNode[key];
            curNode->val=value;
            removeNode(curNode);
            addNode(curNode);
        }else{
            len++;
            addNode(new Node(key,value));
            if(len>limit){
                removeNode(oldest->next);
                len--;
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