#include<vector>
#include<queue>
using namespace std;

class Solution {
    const vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> height(n,vector<int>(m,-1));
        queue<pair<int,int>> process;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    height[i][j]=0;
                    process.push({i,j});
                }
            }
        }
        while(!process.empty()){
            auto [row, col] = process.front();
            process.pop();
            for(auto [diff_x,diff_y]:dirs){
                int next_row=row+diff_x;
                int next_col=col+diff_y;
                if(next_row>=0 && next_row<n && next_col>=0 && next_col<m){
                    if(height[next_row][next_col]==-1){
                        height[next_row][next_col]=height[row][col]+1;
                        process.push({next_row,next_col});
                    }
                }
            }
        }
        return height;
    }
};