#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        auto n=s.size();
        vector<int> freq(26,0);

        auto valid=[&]()->bool{
            int cnt=-1;
            for(auto f:freq) if(f>0){
                if(cnt==-1){
                    cnt=f;
                    continue;
                }

                if(f!=cnt) return false;
            }
            return true;
        };
        
        vector<int> dp(n);

        for(int i=0;i<n;i++){
            dp[i]=i+1;
            freq.assign(26,0);
            freq[s[i]-'a']++;

            for(int j=i-1;j>=0;j--){
                if(valid()) dp[i]=min(dp[i],dp[j]+1);
                freq[s[j]-'a']++;
            }
            if(valid()) dp[i]=1;
        }

        return dp[n-1];
    }
};
