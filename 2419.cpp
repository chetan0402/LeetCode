#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target=*max_element(nums.begin(),nums.end());

        int ans=1;
        int cur=0;

        for(auto num:nums){
            if(num==target){
                cur++;
                ans=max(ans,cur);
            }else cur=0;
        }

        return ans;
    }
};