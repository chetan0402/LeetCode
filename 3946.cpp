#include<vector>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> freeCnt(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0) freeCnt[i]++;
            }
        }

        vector<vector<int>> prevDP(budget+1,vector<int>(2,0));
        vector<vector<int>> dp(budget+1,vector<int>(2,0));
        int ans=0;

        for(int i=1;i<=budget;i++){
            int howMuch=i/items[0][1];
            if(howMuch) prevDP[i][1]=howMuch+freeCnt[0];
            ans=max(ans,prevDP[i][1]);
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=budget;j++){
                dp[j][0]=max({
                    prevDP[j][0],
                    prevDP[j][1],
                    dp[j-1][0],
                });
                dp[j][1]=max({
                    prevDP[j][0],
                    prevDP[j][1],
                    (j-items[i][1]>=0)?(1+dp[j-items[i][1]][1]):0,
                    (j-items[i][1]>=0)?(1+freeCnt[i]+dp[j-items[i][1]][0]):0
                });
                ans=max(ans,dp[j][0]);
                ans=max(ans,dp[j][1]);
            }
            prevDP=dp;
        }

        return ans;
    }
};
