#include<unordered_map>
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
    void solve(TreeNode*root,unordered_map<int,int>&right,int h,int&maxH){
        if(root==nullptr) return;
        right[h]=root->val;
        maxH=max(maxH,h);
        solve(root->left,right,h+1,maxH);
        solve(root->right,right,h+1,maxH);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int> right;
        int height=0;
        solve(root,right,1,height);
        
        vector<int> ans(height);
        for(int i=0;i<height;i++) ans[i]=right[i+1];
        return ans;
    }
};