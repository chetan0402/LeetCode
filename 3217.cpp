#include<vector>
#include<unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(),nums.end());

        ListNode newHead;
        ListNode*cur=&newHead;

        ListNode*ptr=head;

        while(ptr){
            if(!toDelete.count(ptr->val)){
                cur->next=new ListNode(ptr->val);
                cur=cur->next;
            }
            ptr=ptr->next;
        }

        return newHead.next;
    }
};