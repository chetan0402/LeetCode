#include<vector>
#include<queue>
#include<climits>
using namespace std;

const vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=0;

        queue<pair<int,int>> q;
        q.push({0,0});

        while(q.size()){
            auto [x, y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                auto [dx, dy]=dirs[i];
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                int newCost=1+cost[x][y];
                if(i+1==grid[x][y]) newCost--;
                if(cost[nx][ny]>newCost){
                    cost[nx][ny]=newCost;
                    q.push({nx,ny});
                }
            }
        }

        return cost[n-1][m-1];
    }
};