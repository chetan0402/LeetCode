#include<vector>
using namespace std;

class Solution {
    vector<int> parent;
    vector<int> size;
    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }

    void Union(int u,int v){
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.assign(n,1);
        vector<vector<int>> adj(n);
        for(auto&edge:edges){
            Union(edge[0],edge[1]);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> edgeCount(n);
        for(auto&edge:edges) edgeCount[find(edge[0])]++;
        int ans=0;
        for(int i=0;i<n;i++) if(find(i)==i && (size[i]*(size[i]-1)/2)==edgeCount[i]) ans++;
        return ans;
    }
};