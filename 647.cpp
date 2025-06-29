#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=1;i<n;i++) dp[i][i-1]=true;

        for(int offset=1;offset<n;offset++){
            for(int i=0;i+offset<n;i++){
                if(s[i]!=s[i+offset]) dp[i][i+offset]=false;
                else dp[i][i+offset]=dp[i+1][i+offset-1];
            }
        }

        int ans=0;

        for(int i=0;i<n;i++) for(int j=i;j<n;j++) if(dp[i][j]) ans++;

        return ans;
    }
};