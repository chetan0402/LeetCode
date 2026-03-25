#include<vector>
using namespace std;

#define BUY 0
#define SELL 1
#define COOL 2

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int dp[n][3];
        dp[0][BUY]=-prices[0];
        dp[0][SELL]=0;
        dp[0][COOL]=0;
        for(int i=1;i<n;i++){
            dp[i][BUY]=max(dp[i-1][BUY],dp[i-1][COOL]-prices[i]);
            dp[i][SELL]=dp[i-1][BUY]+prices[i];
            dp[i][COOL]=max(dp[i-1][COOL],dp[i-1][SELL]);
        }
        return max({0,dp[n-1][SELL],dp[n-1][COOL]});
    }
};
