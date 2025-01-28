#include<vector>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> value;

    DSU(int n){
        parent=vector<int>(n,-1);
        size=vector<int>(n,1);
        value=vector<int>(n,0);
    }

    int find(int v){
        if(parent[v]==-1) return parent[v]=v;
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
        value[a]+=value[b];
    }

    void set(int num,int val){
        parent[num]=num;
        value[num]=val;
        size[num]=1;
    }
};

class Solution {
    const vector<pair<int,int>> dirs={{-1,0},{0,-1}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DSU dsu(n*m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]){
            int node=i*m+j;
            dsu.set(node,grid[i][j]);
            for(auto [dx, dy]:dirs){
                if(i+dx>=0 && j+dy>=0){
                    if(grid[i+dx][j+dy]){
                        dsu.Union(node,((i+dx)*m+j+dy));
                    }
                }
            }
        }
        int fish=0;
        for(int i=0;i<n*m;i++){
            if(dsu.find(i)==i){
                fish=max(fish,dsu.value[i]);
            }
        }
        return fish;
    }
};