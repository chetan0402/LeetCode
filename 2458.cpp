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

class Solution {
    private:
    vector<int> node_to_level;
    vector<int> firstMax;
    vector<int> firstWho;
    vector<int> secondMax;
public:
    Solution() :
        node_to_level(100001, -1),
        firstMax(100001, -1),
        firstWho(100001, -1),
        secondMax(100001, -1) {}
        
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int lvl=0;
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            if(cur==nullptr){
                if(q.empty()) break;
                q.push(nullptr);
                lvl++;
            }else{
                node_to_level[cur->val]=lvl;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }

        init(root);

        vector<int> ans;

        for(auto&q:queries){
            int curLvl=node_to_level[q];
            if(firstWho[curLvl]==q){
                ans.push_back(curLvl+secondMax[curLvl]);
            }else{
                ans.push_back(curLvl+firstMax[curLvl]);
            }
        }
        
        return ans;
    }

    private:
    int init(TreeNode* root) {
        if (root == nullptr) return -1;
        int best = max(init(root->left), init(root->right));
        int lvl = node_to_level[root->val];
        if (firstMax[lvl] < best + 1) {
            secondMax[lvl] = firstMax[lvl];
            firstMax[lvl] = best + 1;
            firstWho[lvl] = root->val;
        } else if (secondMax[lvl] < best + 1) {
            secondMax[lvl] = best + 1;
        }
        return best + 1;
    }
};