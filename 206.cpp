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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        stack<ListNode*> s;
        ListNode*cur=head;
        while(cur){
            s.push(cur);
            cur=cur->next;
        }
        auto root=s.top();
        s.pop();
        cur=root;
        while(s.size()){
            cur->next=s.top();
            s.pop();
            cur=cur->next;
            cur->next=nullptr;
        }
        return root;
    }
};