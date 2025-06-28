#include<vector>
#include<queue>
#include<tuple>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;
        int n=grid.size();
        int m=grid[0].size();

        queue<tuple<int,int,int>> q;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==2) q.push({i,j,0});

        while(q.size()){
            auto [x, y, minute]=q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(grid[nx][ny]==1) {
                    minutes=max(minutes,minute+1);
                    grid[nx][ny]=2;
                    q.push({nx,ny,minute+1});
                }
            }
        }

        for(auto&row:grid) for(auto val:row) if(val==1) return -1;
        return minutes;
    }
};