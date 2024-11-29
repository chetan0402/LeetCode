#include<vector>
#include<queue>

using namespace std;

const vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int> cur=pq.top();
            pq.pop();
            if(cur[1]==m-1 && cur[2]==n-1){
                return cur[0];
            }
            if(visited[cur[1]][cur[2]]) continue;
            visited[cur[1]][cur[2]]=true;
            for(auto&dir:dirs){
                int i=cur[1]+dir[0];
                int j=cur[2]+dir[1];
                if(i>=0 && i<m && j>=0 && j<n){
                    int waitTime=((grid[i][j]-cur[0])%2==0) ? 1:0;
                    int nextTime=max(grid[i][j]+waitTime,cur[0]+1);
                    pq.push({nextTime,i,j});
                }
            }
        }
        return -1;
    }
};