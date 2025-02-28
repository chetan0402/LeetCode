#include<vector>
#include<string>
using namespace std;

class SolutionMemoTypeDP {
    int dp(int i,int j,string&text1,string&text2,vector<vector<int>>&memo){
        if(i>=text1.size()) return 0;
        if(j>=text2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(text1[i]==text2[j]) return memo[i][j]=1+dp(i+1,j+1,text1,text2,memo);
        else return memo[i][j]=max(dp(i+1,j,text1,text2,memo),dp(i,j+1,text1,text2,memo));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto n=text1.size();
        auto m=text2.size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return dp(0,0,text1,text2,memo);
    }
};

class Solution2DDP {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            auto n=text1.size();
            auto m=text2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                    else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
            return dp[0][0];
        }
    };