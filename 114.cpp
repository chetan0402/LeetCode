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
        void flatten(TreeNode* root) {
            if(root==nullptr) return;
            flatten(root->left);
            flatten(root->right);
            auto curLeft=root->left;
            while(curLeft && curLeft->right) curLeft=curLeft->right;
            if(curLeft){
                curLeft->right=root->right;
                root->right=root->left;
                root->left=nullptr;
            }
        }
    };