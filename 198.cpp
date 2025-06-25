#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
            if(i-1>=0) dp[i]=max(dp[i],dp[i-1]);
            if(i-2>=0) dp[i]=max(dp[i],nums[i]+dp[i-2]);
        }

        return dp.back();
    }
};