#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            auto n=s.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
            for(int i=n-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(s[i]==s[n-1-j]) dp[i][j]=1+dp[i+1][j+1];
                    else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
            return dp[0][0];
        }
    };