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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }

    int dfs(TreeNode*root,int to_beat){
        if(root==nullptr) return 0;
        int ans=0;
        if(root->val >= to_beat){
            ans++;
            ans+=dfs(root->left,root->val);
            ans+=dfs(root->right,root->val);
        }else{
            ans+=dfs(root->left,to_beat);
            ans+=dfs(root->right,to_beat);
        }
        return ans;
    }
};