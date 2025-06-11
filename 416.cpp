#include<vector>
using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            auto n=nums.size();
            int total=0;
            for(auto num:nums) total+=num;
            if(total%2) return false;
            int target=total/2;
            vector<bool> dp(target+1,false);
            dp[0]=true;
            for(auto num:nums){
                for(int possible=target;possible>=num;possible--) if(!dp[possible]) dp[possible]=dp[possible-num];
            }
            return dp[target];
        }
    };

class SolutionTry2 {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(auto num:nums) sum+=num;

        if(sum%2) return false;

        vector<vector<bool>> dp(n,vector<bool>(sum/2 +1));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=sum/2) dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i]>=0) dp[i][j]=(dp[i][j] || dp[i-1][j-nums[i]]);
            }
        }

        return dp[n-1][sum/2];
    }
};