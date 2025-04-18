#include<vector>
#include<unordered_map>
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
    TreeNode*build(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int&postRoot,unordered_map<int,int>&inToI){
        auto n=inorder.size();
        if(inStart<0 || inStart>=n || inEnd<0 || inEnd>=n || postRoot<0 || inStart>inEnd) return nullptr;
        auto root=new TreeNode(postorder[postRoot]);
        auto mid=inToI[root->val];
        postRoot--;
        root->right=build(inorder,mid+1,inEnd,postorder,postRoot,inToI);
        root->left=build(inorder,inStart,mid-1,postorder,postRoot,inToI);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto n=inorder.size();
        unordered_map<int,int> inToI;
        for(int i=0;i<n;i++) inToI[inorder[i]]=i;
        int postRoot=n-1;
        return build(inorder,0,n-1,postorder,postRoot,inToI);
    }
};