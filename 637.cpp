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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        long long sum=0;
        int n=0;
        vector<double> ans;
        while(q.size()){
            auto cur=q.front();
            q.pop();
            if(cur==nullptr){
                ans.push_back(1.0*sum/n);
                sum=0;
                n=0;
                if(q.size()) q.push(nullptr);
                continue;
            }
            sum+=cur->val;
            n++;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return ans;
    }
};