#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> lot;
        queue<TreeNode*> nextlvl;
        lot.push(root);
        TreeNode*cur;
        long long levelSum=0;
        while(!lot.empty() || !nextlvl.empty()){
            if(lot.empty()){
                pq.push(levelSum);
                levelSum=0;
                swap(lot,nextlvl);
            }else{
                cur=lot.front();
                lot.pop();
                levelSum+=cur->val;
                if(cur->left) nextlvl.push(cur->left);
                if(cur->right) nextlvl.push(cur->right);
            }
        }
        pq.push(levelSum);
        if(pq.size()<k) return -1;
        for(int i=1;i<k;i++) pq.pop();
        return pq.top();
    }
};