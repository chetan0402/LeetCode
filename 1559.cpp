#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> color(n,vector<int>(m,0));

        auto dfs=[&](auto&self,int i,int j,int pi,int pj)->bool{
            if(color[i][j]==2) return false;
            if(color[i][j]==1) return true;
            color[i][j]=1;
            for(auto [dx,dy]:dirs){
                int nx=i+dx,ny=j+dy;
                if(nx>=0 & nx<n & ny>=0 & ny<m){
                    if(nx==pi & ny==pj) continue;
                    if(grid[i][j]==grid[nx][ny] && self(self,nx,ny,i,j)) return true;
                }
            }
            color[i][j]=2;
            return false;
        };

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(dfs(dfs,i,j,-1,-1)) return true;

        return false;
    }
};
