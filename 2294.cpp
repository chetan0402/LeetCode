#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=1;

        int curMin=nums[0];
        int curMax=nums[0];

        for(int i=0;i<n;i++){
            curMin=min(curMin,nums[i]);
            curMax=max(curMax,nums[i]);

            if(curMax-curMin>k){
                ans++;
                curMin=nums[i];
                curMax=nums[i];
            }
        }

        return ans;
    }
};