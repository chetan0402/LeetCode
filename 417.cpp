#include<vector>
#include<queue>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
    void setReach(vector<vector<int>>&heights,vector<vector<int>>&reach,queue<pair<int,int>>&q){
        while(q.size()){
            auto [x, y]=q.front();
            q.pop();
            reach[x][y]=1;
            for(auto [dx,dy]:dirs){
                int nx=x+dx;
                int ny=y+dy;
                if(nx<0 || nx>=reach.size() || ny<0 || ny>=reach[0].size()) continue;
                if(reach[nx][ny]!=-1) continue;
                if(heights[nx][ny]<heights[x][y]) continue;
                reach[x][y]=1;
                q.push({nx,ny});
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> pacific(n,vector<int>(m,-1));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++) q.push({i,0});
        for(int j=0;j<m;j++) q.push({0,j});

        setReach(heights,pacific,q);

        vector<vector<int>> atlantic(n,vector<int>(m,-1));

        for(int i=0;i<n;i++) q.push({i,m-1});
        for(int j=0;j<m;j++) q.push({n-1,j});

        setReach(heights,atlantic,q);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(pacific[i][j]==1 && atlantic[i][j]==1) ans.push_back({i,j});

        return ans;
    }
};