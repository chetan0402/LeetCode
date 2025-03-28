#include<vector>
#include<algorithm>
using namespace std;

const vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    
    DSU(int n){
        parent=vector<int>(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.assign(n,1);
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
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
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> qWithI;
        qWithI.reserve(queries.size());
        for(int i=0;i<queries.size();i++) qWithI.push_back({queries[i],i});
        sort(qWithI.begin(),qWithI.end());

        vector<pair<int,int>> cells;
        cells.reserve(grid.size()*grid[0].size());
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[i].size();j++){
            cells.push_back({grid[i][j],i*grid[0].size()+j});
        }
        sort(cells.begin(),cells.end());
        vector<int> ans(queries.size());

        int cellPtr=0;
        DSU dsu(grid.size()*grid[0].size());
        for(auto [q, i]:qWithI){
            while(cellPtr<cells.size() && cells[cellPtr].first<q){
                auto [value, ID]=cells[cellPtr];
                int x=ID/grid[0].size(),y=ID%grid[0].size();
                for(auto [dx, dy]:dirs){
                    int nx=x+dx,ny=y+dy;
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]<q){
                        dsu.Union(ID,nx*grid[0].size()+ny);
                    }
                }
                cellPtr++;
            }
            ans[i]=(q>grid[0][0])?dsu.size[dsu.find(0)]:0;
        }
        return ans;
    }
};