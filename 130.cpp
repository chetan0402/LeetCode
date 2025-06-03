#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        auto n=board.size();
        auto m=board[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        auto dfs=[&](auto&self,int x,int y)->void{
            if(x<0 || x>=n || y<0 || y>=m) return;
            if(vis[x][y] || board[x][y]=='X') return;
            vis[x][y]=true;
            for(auto [dx,dy]:dirs) self(self,x+dx,y+dy);
        };

        for(int i=0;i<n;i++){
            dfs(dfs,i,0);
            dfs(dfs,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(dfs,0,j);
            dfs(dfs,n-1,j);
        }

        for(int i=1;i<n-1;i++) for(int j=1;j<m-1;j++) if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
    }
};