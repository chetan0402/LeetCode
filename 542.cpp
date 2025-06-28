#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(auto&row:mat) for(auto&val:row) if(val==1) val=INT_MAX;
        int n=mat.size();
        int m=mat[0].size();
        queue<tuple<int,int,int>> q;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(mat[i][j]==0) q.push({i,j,0});

        while(q.size()){
            auto [x, y, distance]=q.front();
            q.pop();
            mat[x][y]=min(mat[x][y],distance);
            for(auto [dx,dy]:dirs){
                int nx=x+dx,ny=y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(mat[nx][ny]!=INT_MAX) continue;
                q.push({nx,ny,distance+1});
            }
        }
        
        return mat;
    }
};