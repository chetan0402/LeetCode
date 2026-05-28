#include<vector>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();

        vector<long long> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+nums[i];

        vector<int> suffixMin(n);
        suffixMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) suffixMin[i]=min(suffixMin[i+1],nums[i+1]);

        auto ans=prefixSum[0]-suffixMin[0];
        for(int i=1;i<n-1;i++) ans=max(ans,prefixSum[i]-suffixMin[i]);
        return ans;
    }
};
