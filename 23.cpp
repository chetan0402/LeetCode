#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    ListNode*merge(ListNode*a,ListNode*b){
        ListNode*root=new ListNode();
        ListNode*cur=root;
        while(a && b){
            if(a->val < b->val){
                cur->next=a;
                a=a->next;
            }
            else{
                cur->next=b;
                b=b->next;
            }
            cur=cur->next;
        }
        if(a) cur->next=a;
        if(b) cur->next=b;
        return root->next;
    }
    ListNode*mergeK(vector<ListNode*>&lists,int start,int end){
        if(start>end) return nullptr;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode*a=mergeK(lists,start,mid);
        ListNode*b=mergeK(lists,mid+1,end);
        return merge(a,b);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists,0,lists.size()-1);
    }
};