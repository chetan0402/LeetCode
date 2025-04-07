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