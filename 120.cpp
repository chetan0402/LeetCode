#include<vector>
#include<climits>
using namespace std;

class Solution {
    int dp(vector<vector<int>>&triangle,vector<vector<int>>&memo,int i,int j){
        if(i==memo.size()) return 0;
        if(memo[i][j]!=INT_MAX) return memo[i][j];
        return memo[i][j]=triangle[i][j]+min(dp(triangle,memo,i+1,j),dp(triangle,memo,i+1,j+1));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(),vector<int>(triangle.back().size(),INT_MAX));
        return dp(triangle,memo,0,0);
    }
};