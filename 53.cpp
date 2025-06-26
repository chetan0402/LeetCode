#include<vector>
#include<climits>
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

class SolutionTry2 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int curSum=0;
        for(auto num:nums){
            curSum=max(0,curSum)+num;
            maxSum=max(maxSum,curSum);
        }
        return maxSum;
    }
};