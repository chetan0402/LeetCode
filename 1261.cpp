#include<unordered_set>
#include<queue>
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

class FindElements {
    TreeNode*private_root;
    unordered_set<int> nums;
public:
    FindElements(TreeNode* root) {
        private_root=root;
        root->val=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto cur=q.front();
            nums.insert(cur->val);
            q.pop();
            if(cur->left){
                cur->left->val=2*(cur->val)+1;
                q.push(cur->left);
            }
            if(cur->right){
                cur->right->val=2*(cur->val)+2;
                q.push(cur->right);
            }
        }
    }
    
    bool find(int target) {
        return (nums.find(target)!=nums.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */