struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count(TreeNode*root,int h){
        if(root==nullptr) return 0;
        if(h<=1) return 1;
        auto left=count(root->left,h-1);
        if(left==0) return 0;
        auto right=count(root->right,h-1);
        return left+right;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        auto cur=root;
        int h=0;
        while(cur){
            h++;
            cur=cur->left;
        }
        return (1<<(h-1))-1+count(root,h);
    }
};