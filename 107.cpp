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
    vector<vector<int>> ans;
    void solve(TreeNode*root,int l){
        if(root==nullptr) return;

        if(l>ans.size()) ans.push_back({root->val});
        else ans[l-1].push_back(root->val);

        solve(root->left,l+1);
        solve(root->right,l+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ans.clear();
        solve(root,1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
