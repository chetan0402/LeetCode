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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode*cur=head;
            stack<ListNode*> s;
            while(cur){
                s.push(cur);
                cur=cur->next;
            }
            while(n--) s.pop();
            if(s.size()){
                s.top()->next=s.top()->next->next;
                return head;
            }
            return head->next;
        }
    };