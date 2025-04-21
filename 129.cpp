struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int solve(TreeNode*root,int num){
        if(root->left==nullptr && root->right==nullptr) return 10*num+root->val;
        int ans=0;
        if(root->left) ans+=solve(root->left,10*num+root->val);
        if(root->right) ans+=solve(root->right,10*num+root->val);
        return ans;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};