#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*,Node*> translate;
            translate[nullptr]=nullptr;
            Node*newHead=new Node(0);
            Node*curNew=newHead;
            Node*curOld=head;
            while(curOld!=nullptr){
                curNew->next=new Node(curOld->val);
                translate[curOld]=curNew->next;
                curOld=curOld->next;
                curNew=curNew->next;
            }
            newHead=newHead->next;
            curOld=head;
            curNew=newHead;
            while(curOld!=nullptr){
                curNew->random=translate[curOld->random];
                curOld=curOld->next;
                curNew=curNew->next;
            }
            return newHead;
        }
    };