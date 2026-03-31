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
    vector<int> arr;
    void inorder(TreeNode*root){
        if(root==nullptr) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(int left,int right){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        auto node=new TreeNode(arr[mid]);
        node->left=build(left,mid-1);
        node->right=build(mid+1,right);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        arr.clear();
        inorder(root);
        return build(0,arr.size()-1);
    }
};
