#include<vector>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int> dp(n);
        for(int i=n-1;i>=0;i--) ans=max(ans,dp[i]=energy[i]+(i+k<n?dp[i+k]:0));
        return ans;
    }
};
