#include<vector>
#include<set>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.assign(n,1);
    }

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
};

class Solution {
    const vector<pair<int,int>> p_dirs={{-1,0},{0,-1}};
    const vector<pair<int,int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DSU dsu(n*m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]==0) continue;
            int node=i*m+j;
            for(auto [dx,dy]:p_dirs){
                int new_i=i+dx;
                int new_j=j+dy;
                if(new_i>=0 && new_j>=0 && grid[new_i][new_j]){
                    int new_node=new_i*m+new_j;
                    dsu.Union(node,new_node);
                }
            }
        }
        int ans=0;
        for(int i=0;i<dsu.size.size();i++) ans=max(ans,dsu.size[i]);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]) continue;
            int cur=1;
            set<int> parents;
            for(auto [dx,dy]:dirs){
                int new_i=i+dx;
                int new_j=j+dy;
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]){
                    int new_node=new_i*m+new_j;
                    parents.insert(dsu.find(new_node));
                }
            }
            for(auto p:parents) cur+=dsu.size[p];
            ans=max(ans,cur);
        }
        return ans;
    }
};