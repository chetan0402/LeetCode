#include<queue>
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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> currentLvl;
        queue<TreeNode*> nextLvl;
        currentLvl.push(root);
        int levelSum=0;
        vector<int> levelSums;
        while(!currentLvl.empty() || !nextLvl.empty()){
            if(currentLvl.empty()){
                levelSums.push_back(levelSum);
                levelSum=0;
                swap(currentLvl,nextLvl);
            }else{
                levelSum+=currentLvl.front()->val;
                if(currentLvl.front()->left) nextLvl.push(currentLvl.front()->left);
                if(currentLvl.front()->right) nextLvl.push(currentLvl.front()->right);
                currentLvl.pop();
            }
        }
        levelSums.push_back(levelSum);
        levelSum=0;
        swap(currentLvl,nextLvl);
        currentLvl.push(root);
        root->val=0;
        int depth=0;
        while(!currentLvl.empty() || !nextLvl.empty()){
            if(currentLvl.empty()){
                depth++;
                swap(currentLvl,nextLvl);
            }else{
                if(depth+1 == levelSums.size()) break;
                int sum=levelSums[depth+1];
                if(currentLvl.front()->left) sum-= currentLvl.front()->left->val;
                if(currentLvl.front()->right) sum-= currentLvl.front()->right->val;
                if(currentLvl.front()->left) currentLvl.front()->left->val = sum;
                if(currentLvl.front()->right) currentLvl.front()->right->val = sum;
                if(currentLvl.front()->left) nextLvl.push(currentLvl.front()->left);
                if(currentLvl.front()->right) nextLvl.push(currentLvl.front()->right);
                currentLvl.pop();
            }
        }
        return root;
    }
};