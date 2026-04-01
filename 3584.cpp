#include<vector>
using namespace std;

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        int leftMin=nums[0];
        int leftMax=nums[0];
        if(m==1){
            long long ans=0;
            for(auto num:nums) ans=max(ans,1LL*num*num);
            return ans;
        }

        long long ans=1LL*nums[0]*nums[n-1];
        for(int i=0;i+m-1<n;i++){
            leftMin=min(leftMin,nums[i]);
            leftMax=max(leftMax,nums[i]);
            ans=max({
                ans,
                1LL*leftMin*nums[i+m-1],
                1LL*leftMax*nums[i+m-1]
            });
        }

        return ans;
    }
};
