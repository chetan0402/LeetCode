struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int pathSumStart(TreeNode*root,long long targetSum){
        if(root==nullptr) return 0;
        return (root->val==targetSum)+
        pathSumStart(root->left,targetSum)+
        pathSumStart(root->right,targetSum)+
        pathSumCtn(root->left,targetSum-root->val)+
        pathSumCtn(root->right,targetSum-root->val);
    }
    int pathSumCtn(TreeNode*root,long long targetSum){
        if(root==nullptr) return 0;
        return (root->val==targetSum)+
        pathSumCtn(root->left,targetSum-root->val)+
        pathSumCtn(root->right,targetSum-root->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        return pathSumStart(root,targetSum);
    }
};