#include<vector>
using namespace std;
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            auto n=nums.size();
            int ans=0;
            for(int i=1;i<n-1;i++) if(2*(nums[i-1]+nums[i+1])==nums[i]) ans++;
            return ans;
        }
    };