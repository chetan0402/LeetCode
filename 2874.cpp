#include<vector>
using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            auto n=nums.size();
            vector<int> maxPrefix(n);
            maxPrefix[0]=0;
            for(int i=1;i<n;i++) maxPrefix[i]=max(maxPrefix[i-1],nums[i-1]);
            vector<int> maxSuffix(n);
            maxSuffix[n-1]=0;
            for(int i=n-2;i>=0;i--) maxSuffix[i]=max(maxSuffix[i+1],nums[i+1]);
            long long maxAns=0;
            for(int i=1;i<n-1;i++) maxAns=max(maxAns,1LL*(maxPrefix[i]-nums[i])*maxSuffix[i]);
            return maxAns;
        }
    };