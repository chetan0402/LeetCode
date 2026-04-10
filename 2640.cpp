#include<vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans={2*nums[0]};
        int maxE=nums[0];
        for(int i=1;i<nums.size();i++){
            maxE=max(maxE,nums[i]);
            ans.push_back(ans.back()+nums[i]+maxE);
        }
        return ans;
    }
};
