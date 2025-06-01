#include<algorithm>
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
    int justLess(TreeNode*root){
        root=root->left;
        while(root->right) root=root->right;
        return root->val;
    }
    int justLarge(TreeNode*root){
        root=root->right;
        while(root->left) root=root->left;
        return root->val;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return INT_MAX;
        int ans=INT_MAX;
        if(root->left){
            ans=min(ans,root->val-justLess(root));
        }
        if(root->right){
            ans=min(ans,justLarge(root)-root->val);
        }
        ans=min(ans,getMinimumDifference(root->left));
        ans=min(ans,getMinimumDifference(root->right));
        return ans;
    }
};