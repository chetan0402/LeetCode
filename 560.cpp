#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> sum_freq;
        sum_freq[0]=1;
        int sum=0;
        for(auto num:nums){
            sum+=num;
            ans+=(sum_freq[sum-k]);
            sum_freq[sum]++;
        }
        return ans;
    }
};