struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* inorder(TreeNode* root,int key){
        if(root==nullptr) return nullptr;
        auto right=inorder(root->right,key);
        if(right==nullptr) return root;
        return right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key){
            if(root->left==nullptr & root->right==nullptr) return nullptr;
            auto type=(root->left!=nullptr)+(root->right!=nullptr);
            if(type==1){
                if(root->left!=nullptr) return root->left;
                return root->right;
            }else{
                auto replace=inorder(root->left,key);
                root->val=replace->val;
                root->left=deleteNode(root->left,replace->val);
                return root;
            }
        }

        if(root->val > key) root->left=deleteNode(root->left,key);
        if(root->val < key) root->right=deleteNode(root->right,key);
        return root;
    }
};
