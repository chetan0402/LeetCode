#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode*slow=head;
        ListNode*prevSlow=nullptr;
        ListNode*fast=head;
        while(slow && fast && fast->next){
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prevSlow) prevSlow->next=nullptr;
        ListNode*middle=slow;

        stack<ListNode*> s;
        while(middle){
            s.push(middle);
            middle=middle->next;
            s.top()->next=nullptr;
        }

        ListNode*dummy=new ListNode();
        ListNode*cur=dummy;

        ListNode*curFront=head;
        bool frontNode=true;
        while(curFront && s.size()){
            if(frontNode){
                cur->next=curFront;
                curFront=curFront->next;
            }else{
                cur->next=s.top();
                s.pop();
            }
            frontNode=!frontNode;
            cur=cur->next;
            cur->next=nullptr;
        }
        while(curFront){
            cur->next=curFront;
            curFront=curFront->next;
            cur=cur->next;
            cur->next=nullptr;
        }
        while(s.size()){
            cur->next=s.top();
            s.pop();
            cur=cur->next;
        }

        head=dummy->next;
    }
};