#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<int,Node*> numToNode;

        auto firstDfs=[&](auto&self,Node*cur)->void{
            if(numToNode.count(cur->val)) return;
            numToNode[cur->val]=new Node(cur->val);
            for(auto v:cur->neighbors) self(self,v);
        };

        firstDfs(firstDfs,node);
        
        vector<bool> vis(numToNode.size()+1,false);

        auto secondDfs=[&](auto&self,Node*cur)->void{
            if(vis[cur->val]) return;
            vis[cur->val]=true;

            for(auto v:cur->neighbors) numToNode[cur->val]->neighbors.push_back(numToNode[v->val]);
            for(auto v:cur->neighbors) self(self,v);
        };

        secondDfs(secondDfs,node);

        return numToNode[1];
    }
};