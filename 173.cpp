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

class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    int next() {
        auto node=s.top();
        s.pop();
        if(node->right){
            auto temp=node->right;
            while(temp){
                s.push(temp);
                temp=temp->left;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        return (s.size());
    }
};