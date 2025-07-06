struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=new ListNode();
        ListNode*even=new ListNode();
        ListNode*curOdd=odd;
        ListNode*curEven=even;

        ListNode*cur=head;
        bool which=true;

        while(cur){
            if(which){
                curOdd->next=cur;
                curOdd=curOdd->next;
            }else{
                curEven->next=cur;
                curEven=curEven->next;
            }
            cur=cur->next;
            which=!which;
        }

        curOdd->next=even->next;
        curEven->next=nullptr;

        return odd->next;
    }
};