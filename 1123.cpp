#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionBruteForce {
    TreeNode* lcaNode(TreeNode*root,TreeNode*a,TreeNode*b){
        if(root==nullptr) return nullptr;
        if(root==a || root==b) return root;
        auto left=lcaNode(root->left,a,b);
        auto right=lcaNode(root->right,a,b);
        if(left!=nullptr && right!=nullptr) return root;
        else if(left==nullptr && right!=nullptr) return right;
        else if(left!=nullptr && right==nullptr) return left;
        else return nullptr;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> deepest;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            if(cur==nullptr){
                if(q.empty()) break;
                else{
                    deepest.clear();
                    q.push(nullptr);
                }
            }else{
                deepest.push_back(cur);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        if(deepest.empty()) return nullptr;
        auto curLca=deepest[0];
        for(int i=1;i<deepest.size();i++) curLca=lcaNode(root,curLca,deepest[i]);
        return curLca;
    }
};

class SolutionOptimal {
    pair<TreeNode*,int> dfs(TreeNode*root){
        if(root==nullptr) return {nullptr,0};
        auto [leftNode, leftHeight]=dfs(root->left);
        auto [rightNode, rightHeight]=dfs(root->right);
        if(leftHeight>rightHeight) return {leftNode,leftHeight+1};
        else if(rightHeight>leftHeight) return {rightNode,rightHeight+1};
        else return {root,leftHeight+1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};