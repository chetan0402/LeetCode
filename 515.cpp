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
    vector<int> _ans;
    void solve(TreeNode*root,int l){
        if(root==nullptr) return;

        if(_ans.size()<l) _ans.push_back(root->val);
        else _ans[l-1]=max(_ans[l-1],root->val);

        solve(root->left,l+1);
        solve(root->right,l+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        _ans.clear();
        solve(root,1);
        return _ans;
    }
};
