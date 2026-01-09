#include<vector>
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
    vector<int> height;
    int build(TreeNode*root,int h){
        if(root==nullptr) return -1;
        return height[root->val]=max({build(root->left,h+1),build(root->right,h+1),h});
    }
    TreeNode* solve(TreeNode*root){
        if(root->left!=nullptr & root->right!=nullptr){
            if(height[root->val]==height[root->left->val] &
            height[root->val]==height[root->right->val]
            ) return root;
            if(height[root->val]==height[root->left->val]) return solve(root->left);
            if(height[root->val]==height[root->right->val]) return solve(root->right);
        }
        if(root->left) return solve(root->left);
        if(root->right) return solve(root->right);
        return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height.assign(500+1,-1);
        build(root,0);
        return solve(root);
    }
};
