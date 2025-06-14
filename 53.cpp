#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++){
            prev=nums[i]+max(0,prev);
            maxSum=max(maxSum,prev);
        }
        return maxSum;
    }
};