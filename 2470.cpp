#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>k || k%nums[i]!=0) continue;
            int cur=1;
            for(int j=i;j<n;j++){
                if(nums[j]>k || k%nums[j]!=0) break;
                cur=lcm(cur,nums[j]);
                if(cur==k) ans++;
                if(cur>k) break;
            }
        }
        return ans;
    }
};