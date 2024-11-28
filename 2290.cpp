#include<vector>
#include<queue>
#include<climits>

using namespace std;

const vector<vector<int>> dirs ={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> min_dis(m,vector<int>(n,INT_MAX));

        min_dis[0][0]=0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({min_dis[0][0],0,0});

        while(!pq.empty()){
            vector<int> cur=pq.top();
            pq.pop();
            if(cur[1]==m-1 && cur[2]==n-1) return cur[0];

            for(auto&dir:dirs){
                int i=cur[1]+dir[0];
                int j=cur[2]+dir[1];
                if(i>=0 && i<m && j>=0 && j<n){
                    int new_dis=cur[0]+grid[i][j];
                    if(new_dis<min_dis[i][j]){
                        min_dis[i][j]=new_dis;
                        pq.push({new_dis,i,j});
                    }
                }
            }
        }
        return min_dis[m-1][n-1];
    }
};