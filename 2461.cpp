#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long curSum=0;
        unordered_map<int,int> freq;
        for(int i=0;i<k;i++){
            freq[nums[i]]++;
            curSum+=nums[i];
        }
        if(freq.size()==k) sum=curSum;
        for(int i=1;i<=n-k;i++){
            curSum-=nums[i-1];
            curSum+=nums[i+k-1];
            
            freq[nums[i-1]]--;
            if(freq[nums[i-1]]==0) freq.erase(nums[i-1]);

            freq[nums[i+k-1]]++;

            if(freq.size()==k) sum=max(sum,curSum);
        }
        return sum;
    }
};