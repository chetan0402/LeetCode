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
    TreeNode*build(vector<int>&preorder,int startPre,int endPre,vector<int>&inorder,int startIn,int endIn,unordered_map<int,int>&inToI){
        if(startPre<0 || startPre>=preorder.size() || endPre<0 || endPre>=preorder.size() || startIn<0 || startIn>=inorder.size() || endIn<0 || endIn>=inorder.size() || startPre>endPre || startIn>endIn) return nullptr;
        auto root=preorder[startPre];
        int startPreLeft=startPre+1;
        int startPreRight=startPre+1;
        while(startPreRight<preorder.size() && inToI[preorder[startPreRight]]<inToI[root]) startPreRight++;
        auto left=build(preorder,startPreLeft,startPreRight-1,inorder,startIn,inToI[root]-1,inToI);
        auto right=build(preorder,startPreRight,endPre,inorder,inToI[root]+1,endIn,inToI);
        auto node=new TreeNode(root);
        node->left=left;
        node->right=right;
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inToI;
        for(int i=0;i<inorder.size();i++) inToI[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inToI);
    }
};