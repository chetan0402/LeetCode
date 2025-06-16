#include<vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;

        vector<int> suffix(n+1);
        suffix[n]=0;

        for(int i=n-1;i>=0;i--) suffix[i]=max(suffix[i+1],nums[i]);

        for(int i=0;i<n;i++){
            if(suffix[i+1]<=nums[i]) continue;
            ans=max(ans,suffix[i+1]-nums[i]);
        }
        return ans;
    }
};