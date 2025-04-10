struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode*result=nullptr;
            ListNode*end=nullptr;
            while(list1 && list2){
                if(list1->val < list2->val){
                    if(end){
                        end->next=list1;
                        end=end->next;
                    }
                    else result=end=list1;
                    list1=list1->next;
                }else{
                    if(end){
                        end->next=list2;
                        end=end->next;
                    }
                    else result=end=list2;
                    list2=list2->next;
                }
            }
            while(list1){
                if(end){
                        end->next=list1;
                        end=end->next;
                    }
                    else result=end=list1;
                    list1=list1->next;
            }
            while(list2){
                if(end){
                        end->next=list2;
                        end=end->next;
                    }
                    else result=end=list2;
                    list2=list2->next;
            }
            return result;
        }
    };