#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


const int MOD=1e9+7;

class Solution {
    unordered_map<TreeNode*,int> memo;
    int tsum;
    long long sum(TreeNode*node){
        if(node==nullptr) return 0;
        if(memo.count(node)) return memo[node];
        return memo[node]=node->val+sum(node->left)+sum(node->right);
    }
    long long solve(TreeNode*node){
        if(node==nullptr) return 0;
        return max({
            (tsum-sum(node))*sum(node),
            solve(node->left),
            solve(node->right)
        });
    }
public:
    int maxProduct(TreeNode* root) {
        tsum=sum(root);
        return solve(root)%MOD;
    }
};
