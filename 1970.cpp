#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{1,1},{0,1},{-1,1},{1,0},{-1,0},{1,-1},{0,-1},{-1,-1}};

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        size.assign(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto convert=[&](int i,int j)->int{
            return i*col+j;
        };
        DSU dsu(row*col);
        vector<vector<bool>> grid(row,vector<bool>(col,false));

        for(int i=0;i<cells.size();i++){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=true;

            for(auto [dx,dy]:dirs){
                auto nx=r+dx;
                auto ny=c+dy;
                if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny])
                dsu.Union(convert(r,c),convert(nx,ny));
            }

            bool left=false;
            for(int j=0;j<row && !left;j++)
            if(grid[j][0] && dsu.find(convert(j,0))==dsu.find(convert(r,c)))
            left=true;

            if(!left) continue;
            bool right=false;
            for(int j=0;j<row && !right;j++)
            if(grid[j][col-1] && dsu.find(convert(j,col-1))==dsu.find(convert(r,c)))
            right=true;

            if(left && right) return i;
        }

        return cells.size();
    }
};