#include<string>
#include<algorithm>
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
    void generateAll(TreeNode*root,string&temp,string&ans){
        if(root->left==nullptr && root->right==nullptr){
            temp.push_back(root->val+'a');
            reverse(temp.begin(),temp.end());
            ans=min(ans,temp);
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return;
        }
        temp.push_back(root->val+'a');
        if(root->left) generateAll(root->left,temp,ans);
        if(root->right) generateAll(root->right,temp,ans);
        temp.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans="~";
        string temp="";
        generateAll(root,temp,ans);
        return ans;
    }
};