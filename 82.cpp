struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode*cur=head;
            ListNode*newHead=new ListNode();
            ListNode*newCur=newHead;
            while(cur){
                bool dup=false;
                while(cur->next && cur->val==cur->next->val){
                    cur=cur->next;
                    dup=true;
                }
                if(!dup){
                    newCur->next=cur;
                    newCur=newCur->next;
                    cur=cur->next;
                    newCur->next=nullptr;
                }else cur=cur->next;
            }
            return newHead->next;
        }
    };