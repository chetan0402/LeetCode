#include<vector>
#include<queue>
using namespace std;

const vector<vector<pair<int,int>>> dirs={
    {{0,-1},{0,1}},
    {{1,0},{-1,0}},
    {{0,-1},{1,0}},
    {{1,0},{0,1}},
    {{0,-1},{-1,0}},
    {{0,1},{-1,0}}
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({0,0});
        vis[0][0]=true;

        while(q.size()){
            auto [x,y]=q.front();q.pop();
            if(x==n-1 & y==m-1) return true;

            for(auto [dx,dy]:dirs[grid[x][y]-1]){
                int nx=x+dx,ny=y+dy;
                if((nx>=0 & nx<n & ny>=0 & ny<m) && !vis[nx][ny]){
                    for(auto [ddx,ddy]:dirs[grid[nx][ny]-1]){
                        int nnx=nx+ddx,nny=ny+ddy;
                        if(nnx>=0 & nnx<n & nny>=0 & nny<m & nnx==x & nny==y){
                            q.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
