#include<vector>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> bitwise;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.assign(n,0);
        bitwise.assign(n,-1);
    }

    int find(int u){
        if(parent[u]==u) return u;
        else return parent[u]=find(parent[u]);
    }

    void Union(int u,int v,int edge){
        int a=find(u);
        int b=find(v);
        if(a==b){
            bitwise[a]&=edge;
            return;
        }
        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        bitwise[a]&=bitwise[b];
        bitwise[a]&=edge;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto edge:edges){
            dsu.Union(edge[0],edge[1],edge[2]);
        }
        vector<int> ans;
        ans.reserve(query.size());
        for(auto q:query){
            int u=dsu.find(q[0]);
            int v=dsu.find(q[1]);
            if(u!=v) ans.push_back(-1);
            else ans.push_back(dsu.bitwise[u]);
        }
        return ans;
    }
};