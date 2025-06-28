struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    bool equal(TreeNode*root1,TreeNode*root2){
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        return (root1->val==root2->val && equal(root1->left,root2->left) && equal(root1->right,root2->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(equal(root,subRoot)) return true;
        if(root->left) if(isSubtree(root->left,subRoot)) return true;
        if(root->right) if(isSubtree(root->right,subRoot)) return true;
        return false;
    }
};