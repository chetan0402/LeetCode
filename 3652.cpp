#include<vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();

        vector<long long> prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+(prices[i-1]*strategy[i-1]);

        long long ans=prefix.back();

        vector<long long> prefixP(n+1);
        prefixP[0]=0;
        for(int i=1;i<=n;i++) prefixP[i]=prefixP[i-1]+prices[i-1];

        for(int i=0;i+k<=n;i++){
            int wStart=i;
            int wEnd=i+k; // not included
            int wMid=i+(k/2);

            ans=max(ans,prefix[wStart]+(prefixP[wEnd]-prefixP[wMid])+(prefix.back()-prefix[wEnd]));
        }

        return ans;
    }
};
