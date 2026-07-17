#include<vector>
#include<queue>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j] && !vis[i][j]) {
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j]=true;

            int cur=0;

            while(q.size()){
                auto [x,y]=q.front();q.pop();
                cur=(cur+grid[x][y])%k;
                for(auto [dx,dy]:dirs) if(
                    x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m &&
                    grid[x+dx][y+dy]>0 && !vis[x+dx][y+dy]
                ){
                    vis[x+dx][y+dy]=true;
                    q.push({x+dx,y+dy});
                }
            }

            if(cur%k==0) ans++;
        }

        return ans;
    }
};
