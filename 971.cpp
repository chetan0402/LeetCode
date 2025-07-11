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
    void preorder(TreeNode*root,vector<int>&voy,int&i,vector<int>&ans,bool&valid){
        if(!valid) return;
        if(root==nullptr) return;
        if(root->val!=voy[i]){
            valid=false;
            return;
        }
        if(root->left==nullptr && root->right==nullptr) return;
        if(root->left==nullptr || root->right==nullptr){
            i++;
            if(root->left) preorder(root->left,voy,i,ans,valid);
            if(root->right) preorder(root->right,voy,i,ans,valid);
            return;
        }
        
        if(voy[i+1]!=root->left->val){
            swap(root->left,root->right);
            ans.push_back(root->val);
        }
        i++;
        preorder(root->left,voy,i,ans,valid);
        i++;
        preorder(root->right,voy,i,ans,valid);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int i=0;
        bool valid=true;
        preorder(root,voyage,i,ans,valid);
        if(valid) return ans;
        else return {-1};
    }
};