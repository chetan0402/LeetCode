#include<climits>
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
    bool valid(TreeNode*root,long long lowerBound,long long upperBound){
        if(root==nullptr) return true;
        if(root->val <= lowerBound) return false;
        if(root->val >= upperBound) return false;
        return (valid(root->left,lowerBound,root->val) && valid(root->right,root->val,upperBound));
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};