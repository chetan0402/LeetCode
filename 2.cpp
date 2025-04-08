struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode*ans=new ListNode();
            ListNode*cur=ans;
            int carry=0;
            while(l1!=nullptr && l2!=nullptr){
                cur->val=(l1->val+l2->val+carry);
                carry=0;
                if(cur->val>=10){
                    carry=1;
                    cur->val-=10;
                }
                l1=l1->next;
                l2=l2->next;
                if(l1 || l2 || carry)cur->next=new ListNode();
                cur=cur->next;
            }
            while(l1!=nullptr){
                cur->val=(l1->val+carry);
                carry=0;
                if(cur->val>=10){
                    carry=1;
                    cur->val-=10;
                }
                l1=l1->next;
                if(l1 || carry) cur->next=new ListNode();
                cur=cur->next;
            }
            while(l2!=nullptr){
                cur->val=(l2->val+carry);
                carry=0;
                if(cur->val>=10){
                    carry=1;
                    cur->val-=10;
                }
                l2=l2->next;
                if(l2 || carry) cur->next=new ListNode();
                cur=cur->next;
            }
            if(carry) cur->val=1;
            return ans;
        }
    };