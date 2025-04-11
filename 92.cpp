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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode*cur=head;
            ListNode*newHead=new ListNode();
            ListNode*curNew=newHead;
            int idx=1;
            stack<ListNode*> s;
            while(cur!=nullptr){
                if(idx>=left && idx<=right){
                    s.push(cur);
                    cur=cur->next;
                    s.top()->next=nullptr;
                    idx++;
                }else if(idx>right){
                    while(s.size()){
                        curNew->next=s.top();
                        s.pop();
                        curNew=curNew->next;
                    }
                    curNew->next=cur;
                    cur=cur->next;
                    curNew=curNew->next;
                    curNew->next=nullptr;
                    idx++;
                }else{
                    curNew->next=cur;
                    cur=cur->next;
                    curNew=curNew->next;
                    curNew->next=nullptr;
                    idx++;
                }
            }
            while(s.size()){
                curNew->next=s.top();
                s.pop();
                curNew=curNew->next;
            }
            return newHead->next;
        }
    };