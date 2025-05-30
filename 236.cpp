#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        if(root==p || root==q) return root;
        auto left=lowestCommonAncestor(root->left,p,q);
        auto right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
};