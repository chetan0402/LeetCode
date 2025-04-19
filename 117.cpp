#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
        Node* connect(Node* root) {
            if(root==nullptr) return root;
            queue<Node*> q;
            Node*prev=nullptr;
            q.push(root);
            q.push(nullptr);
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                if(cur==nullptr){
                    if(!q.empty()) q.push(nullptr);
                    prev=nullptr;
                    continue;
                }
                if(prev) prev->next=cur;
                prev=cur;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            return root;
        }
    };