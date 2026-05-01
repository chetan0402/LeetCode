#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int _k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(_k+1,
                                       vector<vector<int>>(n, vector<int>(m)));
        dp[0][0][0] = 0;

        for (int k = 0; k <= _k; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (k == 0 & i == 0 & j == 0)
                        continue;
                    auto left = ((k - grid[i][j] < 0 | j == 0) ? -1 : dp[k - grid[i][j]][i][j - 1]);
                    auto up = ((k - grid[i][j] < 0 | i == 0) ? -1 : dp[k - grid[i][j]][i - 1][j]);
                    auto nothing = (k == 0 ? -1 : dp[k - 1][i][j]);
                    dp[k][i][j] = max({left, up, nothing});
                    if(dp[k][i][j]!=-1) dp[k][i][j]+=grid[i][j];
                }
            }
        }

        return dp[_k][n-1][m-1];
    }
};

int main(){
    vector<vector<int>> grid={
        {0,1},
        {2,0}
    };
    Solution s;
    s.maxPathScore(grid,1);
    return 0;
}