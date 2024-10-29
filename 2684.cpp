#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int moves=0;
        vector<vector<int>> memo(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            moves=max(moves,dp(grid,memo,i,0));
        }
        return moves;
    }

    int dp(vector<vector<int>>&grid,vector<vector<int>>&memo,int i,int j){
        if(i<0 || i>=memo.size() || j<0 || j>=memo[0].size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int maxMoves=0;
        if(j+1<grid[0].size()){
            if(i>0 && grid[i-1][j+1]>grid[i][j]) maxMoves=max(maxMoves,1+dp(grid,memo,i-1,j+1));
            if(grid[i][j+1]>grid[i][j]) maxMoves=max(maxMoves,1+dp(grid,memo,i,j+1));
            if(i<grid.size()-1 && grid[i+1][j+1]>grid[i][j]) maxMoves=max(maxMoves,1+dp(grid,memo,i+1,j+1));
        }
        return memo[i][j]=maxMoves;
    }
};