#include<vector>
#include<stack>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> lvl;

        stack<TreeNode*> currentlvl;
        stack<TreeNode*> nextlvl;

        currentlvl.push(root);

        bool leftToRight=true;

        while(currentlvl.size() || nextlvl.size() || lvl.size()){
            if(currentlvl.empty()){
                swap(currentlvl,nextlvl);
                leftToRight=!leftToRight;
                ans.push_back(lvl);
                lvl.clear();
                continue;
            }
            auto cur=currentlvl.top();
            currentlvl.pop();

            lvl.push_back(cur->val);
            
            if(leftToRight){
                if(cur->left) nextlvl.push(cur->left);
                if(cur->right) nextlvl.push(cur->right);
            }else{
                if(cur->right) nextlvl.push(cur->right);
                if(cur->left) nextlvl.push(cur->left);
            }
        }
        return ans;
    }
};