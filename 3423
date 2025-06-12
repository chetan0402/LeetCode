#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=abs(nums.front()-nums.back());
        for(int i=0;i<n-1;i++) ans=max(ans,abs(nums[i]-nums[i+1]));
        return ans;
    }
};