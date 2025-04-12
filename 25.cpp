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
    bool kExists(ListNode*head,int k){
        ListNode*cur=head;
        while(k--){
            if(cur==nullptr) return false;
            cur=cur->next;
        }
        return true;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*newHead=new ListNode();
        ListNode*curNew=newHead;
        ListNode*curOld=head;
        while(kExists(curOld,k)){
            int tempK=k;
            stack<ListNode*> s;
            while(tempK--){
                s.push(curOld);
                curOld=curOld->next;
            }
            while(s.size()){
                curNew->next=s.top();
                s.pop();
                curNew=curNew->next;
            }
        }
        curNew->next=curOld;
        return newHead->next;
    }
};