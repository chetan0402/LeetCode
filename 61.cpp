struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    ListNode* right(ListNode*head,int k){
        if(k==0) return head;
        if(head==nullptr) return nullptr;
        ListNode*cur=head;
        ListNode*prev;
        while(cur->next){
            prev=cur;
            cur=cur->next;
        }
        if(prev) prev->next=nullptr;
        if(cur!=head) cur->next=head;
        return right(cur,k-1);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*cur=head;
        int len=0;
        while(cur){
            cur=cur->next;
            len++;
        }
        if(len<=1) return head;
        return right(head,k%len);
    }
};