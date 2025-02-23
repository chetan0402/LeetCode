#include<string>
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
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            auto n=traversal.size();
            int index=0;
            int rootVal=0;
            for(;index<n && isdigit(traversal[index]);index++) rootVal=(rootVal*10+(traversal[index]-'0'));
            TreeNode*root=new TreeNode(rootVal);
            vector<TreeNode*> s;
            s.push_back(root);
            while(index<n){
                int depth=0;
                while(traversal[index]=='-'){
                    depth++;
                    index++;
                }
                while(s.size()>depth) s.pop_back();
                int newVal=0;
                for(;index<n && isdigit(traversal[index]);index++) newVal=(newVal*10+(traversal[index]-'0'));
                TreeNode*newNode=new TreeNode(newVal);
                if(s.back()->left) s.back()->right=newNode;
                else s.back()->left=newNode;
                s.push_back(newNode);
            }
            return root;
        }
    };