#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

const vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));

        int i=0;
        int j=0;
        int dir=0;

        while(head){
            ans[i][j]=head->val;
            head=head->next;
            if(!head) continue;
            while(
                i+dirs[dir].first<0 ||
                i+dirs[dir].first>=m ||
                j+dirs[dir].second<0 ||
                j+dirs[dir].second>=n ||
                ans[i+dirs[dir].first][j+dirs[dir].second]!=-1
            )dir=(dir+1)%dirs.size();
            i+=dirs[dir].first;
            j+=dirs[dir].second;
        }

        return ans;
    }
};
