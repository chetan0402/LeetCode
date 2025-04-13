struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode*smallHead=new ListNode();
            ListNode*largeHead=new ListNode();
            ListNode*smallCur=smallHead;
            ListNode*largeCur=largeHead;
            ListNode*cur=head;
            while(cur){
                if(cur->val<x){
                    smallCur->next=cur;
                    cur=cur->next;
                    smallCur=smallCur->next;
                    smallCur->next=nullptr;
                }else{
                    largeCur->next=cur;
                    cur=cur->next;
                    largeCur=largeCur->next;
                    largeCur->next=nullptr;
                }
            }
            smallCur->next=largeHead->next;
            return smallHead->next;
        }
    };