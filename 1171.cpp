struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> prefix;
        auto dummy=new ListNode(0,head);
        int sum=0;
        auto cur=dummy;
        while(cur){
            sum+=cur->val;
            if(prefix.count(sum)){
                auto prev=prefix[sum];
                cur=prev->next;
                int p=sum+cur->val;
                while(p!=sum){
                    prefix.erase(p);
                    cur=cur->next;
                    p+=cur->val;
                }
                prev->next=cur->next;
            }else prefix[sum]=cur;

            cur=cur->next;
        }
        return dummy->next;
    }
};
