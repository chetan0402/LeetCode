#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> memo(n,vector<int>(m,-1));

        auto dfs=[&](auto&self,int x,int y)->int{
            if(memo[x][y]!=-1) return memo[x][y];
            memo[x][y]=1;
            for(auto [dx,dy]:dirs){
                int nx=x+dx;
                int ny=y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(matrix[nx][ny]<matrix[x][y]) memo[x][y]=max(memo[x][y],1+self(self,nx,ny));
            }
            return memo[x][y];
        };

        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans=max(ans,dfs(dfs,i,j));

        return ans;
    }
};