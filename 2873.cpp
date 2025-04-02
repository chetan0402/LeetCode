#include<vector>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            auto n=nums.size();
            long long maximum=0;
            vector<int> maxSuffix(n+1);
            maxSuffix[n]=0;
            for(int i=n-1;i>=0;i--) maxSuffix[i]=max(maxSuffix[i+1],nums[i]);
            vector<int> maxPrefix(n+1);
            maxPrefix[0]=0;
            for(int i=1;i<=n;i++) maxPrefix[i]=max(maxPrefix[i-1],nums[i-1]);
            for(int i=1;i<n;i++) maximum=max(maximum,1LL*(maxPrefix[i]-nums[i])*maxSuffix[i+1]);
            return maximum;
        }
    };