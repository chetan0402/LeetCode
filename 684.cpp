#include<vector>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent=vector<int>(n,-1);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        size=vector<int>(n,1);
    }

    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }

    void Union(int u,int v){
        int a=find(u);
        int b=find(v);
        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto edge:edges){
            if(dsu.find(edge[0]-1)==dsu.find(edge[1]-1)) return edge;
            dsu.Union(edge[0]-1,edge[1]-1);
        }
        return {};
    }
};