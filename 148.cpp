#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    pair<ListNode*,ListNode*> merge(ListNode*a,ListNode*b,ListNode*end){
        ListNode*root=new ListNode();
        ListNode*cur=root;

        ListNode*curA=a;
        ListNode*curB=b;

        while(curA!=b && curB!=end && curA && curB){
            if(curA->val < curB->val){
                cur->next=curA;
                curA=curA->next;
            }else{
                cur->next=curB;
                curB=curB->next;
            }
            cur=cur->next;
            cur->next=nullptr;
        }
        while(curA!=b && curA){
            cur->next=curA;
            curA=curA->next;
            cur=cur->next;
            cur->next=nullptr;
        }
        while(curB!=end && curB){
            cur->next=curB;
            curB=curB->next;
            cur=cur->next;
            cur->next=nullptr;
        }

        return {root->next,cur};
    }
    int size(ListNode*head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* ahead(ListNode*head,int k){
        while(head && k){
            k--;
            head=head->next;
        }
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        int n=size(head);
        for(int subSize=1;subSize<n;subSize*=2){
            ListNode*root=new ListNode();
            ListNode*cur=root;
            ListNode*start=head;

            while(start){
                auto left=start;
                auto mid=ahead(left,subSize);
                auto right=ahead(mid,subSize);

                start=right;

                auto [newLeft, newRight] =merge(left,mid,right);
                cur->next=newLeft;
                cur=newRight;
            }

            head=root->next;
        }

        return head;
    }
};