#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            auto n=str1.size();
            auto m=str2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(str1[i]==str2[j]) dp[i][j]=1+dp[i+1][j+1];
                    else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
            string ans;
            int i=0;
            int j=0;
            while(i<n && j<m){
                if(str1[i]==str2[j]){
                    ans.push_back(str1[i]);
                    i++;
                    j++;
                }else{
                    if(dp[i+1][j]>dp[i][j+1]) ans.push_back(str1[i++]);
                    else ans.push_back(str2[j++]);
                }
            }
            while(i<n){
                ans.push_back(str1[i]);
                i++;
            }
            while(j<m){
                ans.push_back(str2[j]);
                j++;
            }
            return ans;
        }
    };