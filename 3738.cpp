#include<vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefix(n);
        prefix[0]=1;

        for(int i=1;i<n;i++)
        if(nums[i-1]>nums[i]) prefix[i]=1;
        else prefix[i]=prefix[i-1]+1;

        vector<int> suffix(n);
        suffix[n-1]=1;

        for(int i=n-2;i>=0;i--)
        if(nums[i+1]<nums[i]) suffix[i]=1;
        else suffix[i]=suffix[i+1]+1;

        int ans=max(prefix[0],suffix[n-1]);
        for(int i=0;i+1<n;i++) ans=max(ans,prefix[i]+1);
        for(int i=1;i<n;i++) ans=max(ans,suffix[i]+1);

        for(int i=0;i+2<n;i++)
        if(nums[i]<=nums[i+2])
        ans=max(ans,prefix[i]+1+suffix[i+2]);

        return ans;
    }
};
