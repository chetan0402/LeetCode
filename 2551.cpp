#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            auto n=weights.size();
            vector<long long> pairSum(n-1);
            for(int i=0;i<n-1;i++) pairSum[i]=weights[i]+weights[i+1];
            sort(pairSum.begin(),pairSum.end());
    
            long long ans=0;
            for(int i=0;i<k-1;i++) ans+=pairSum[n-2-i]-pairSum[i];
            return ans;
        }
    };