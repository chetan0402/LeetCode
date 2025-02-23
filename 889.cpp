#include<vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    TreeNode*make(vector<int>&preorder,int startPre,int endPre,vector<int>&postorder,int startPost,int endPost){
        if(startPre>endPre) return nullptr;
        TreeNode*root=new TreeNode(preorder[startPre]);
        if(startPre==endPre) return root;
        int numberOfLeftElements=1;
        while(postorder[startPost+numberOfLeftElements-1]!=preorder[startPre+1]) numberOfLeftElements++;
        root->left=make(preorder,startPre+1,startPre+numberOfLeftElements,postorder,startPost,startPost+numberOfLeftElements);
        root->right=make(preorder,startPre+1+numberOfLeftElements,endPre,postorder,startPost+numberOfLeftElements,endPost-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return make(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};