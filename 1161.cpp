#include<queue>
#include<climits>

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
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int maxLvl=-1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int curSum=0;
        int curLvl=0;
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            if(cur==nullptr){
                if(curSum>maxSum){
                    maxSum=curSum;
                    maxLvl=curLvl;
                }
                curLvl++;
                curSum=0;
                if(!q.empty()) q.push(nullptr);
            }else{
                curSum+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return maxLvl+1;
    }
};

class Solution2 {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> lsum;

        auto dfs=[&](auto&self,TreeNode*node,int l)->void{
            if(node==nullptr) return;
            if(l==lsum.size()) lsum.push_back(node->val);
            else lsum[l]+=node->val;

            self(self,node->left,l+1);
            self(self,node->right,l+1);
        };

        dfs(dfs,root,0);

        int ansI=0;
        for(int i=1;i<lsum.size();i++) if(lsum[i]>lsum[ansI]) ansI=i;
        return ansI+1;
    }
};
