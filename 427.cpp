#include<vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node*build(vector<vector<int>>&grid,int left,int right,int top,int down){
        if(left>right || top>down) return nullptr;
        Node*root=new Node(grid[top][left],true);
        for(int i=top;i<=down;i++) for(int j=left;j<=right;j++) if(grid[i][j]!=root->val){
            root->isLeaf=false;
            break;
        }
        if(root->isLeaf) return root;
        int hMid=left+(right-left)/2;
        int vMid=top+(down-top)/2;
        root->topLeft=build(grid,left,hMid,top,vMid);
        root->topRight=build(grid,hMid+1,right,top,vMid);
        root->bottomLeft=build(grid,left,hMid,vMid+1,down);
        root->bottomRight=build(grid,hMid+1,right,vMid+1,down);
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,grid[0].size()-1,0,grid.size()-1);
    }
};