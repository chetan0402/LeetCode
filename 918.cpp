#include<vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minCur=0;
        int minSum=nums[0];
        int maxCur=0;
        int maxSum=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            minCur=nums[i]+min(0,minCur);
            minSum=min(minSum,minCur);

            maxCur=nums[i]+max(0,maxCur);
            maxSum=max(maxSum,maxCur);
        }
        if(sum==minSum) return maxSum;
        return max(maxSum,sum-minSum);
    }
};