#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        auto dfs=[&](auto&self,int i,int j)->void{
            if(i<0 || i>=n || j<0 || j>=m) return;
            if(vis[i][j]) return;
            if(grid[i][j]=='0') return;
            vis[i][j]=true;
            for(auto [dx,dy]:dirs) self(self,i+dx,j+dy);
        };

        int ans=0;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]=='1' && !vis[i][j]){
            ans++;
            dfs(dfs,i,j);
        }

        return ans;
    }
};