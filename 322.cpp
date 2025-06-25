#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;

        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                int j=i-coin;
                if(j<0) continue;
                if(dp[j]==-1) continue;
                if(dp[i]==-1) dp[i]=dp[j]+1;
                else dp[i]=min(dp[i],dp[j]+1);
            }
        }

        return dp[amount];
    }
};