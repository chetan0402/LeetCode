#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    TreeNode* findTarget(TreeNode*root,TreeNode*target,unordered_map<TreeNode*,TreeNode*>&cToP){
        if(root==nullptr) return nullptr;
        if(root->val==target->val) return root;
        if(root->left) cToP[root->left]=root;
        if(root->right) cToP[root->right]=root;
        auto left=findTarget(root->left,target,cToP);
        if(left) return left;
        return findTarget(root->right,target,cToP);
    }

    void dfsDown(TreeNode*node,int k,vector<int>&ans){
        if(node==nullptr) return;
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        dfsDown(node->left,k-1,ans);
        dfsDown(node->right,k-1,ans);
    }

    void dfsUp(TreeNode*node,int k,vector<int>&ans,unordered_map<TreeNode*,TreeNode*>&cToP,TreeNode*prev){
        if(node==nullptr) return;
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        if(node->left!=prev) dfsDown(node->left,k-1,ans);
        if(node->right!=prev) dfsDown(node->right,k-1,ans);
        dfsUp(cToP[node],k-1,ans,cToP,node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> childToParent;

        auto targetFound=findTarget(root,target,childToParent);

        vector<int> ans;

        dfsDown(targetFound,k,ans);
        dfsUp(childToParent[targetFound],k-1,ans,childToParent,targetFound);

        return ans;
    }
};