#include<vector>
#include<string>
using namespace std;

class Solution {
    bool dp(string&s,vector<vector<int>>&memo,int start,int end){
        if(start>end) return true;
        if(memo[start][end]!=-1) return memo[start][end];
        if(s[start]!=s[end]) return memo[start][end]=false;
        return memo[start][end]=dp(s,memo,start+1,end-1);
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) memo[i][i]=true;

        int start=0;
        int len=0;
        for(int i=0;i<n;i++) for(int j=i;j<n;j++) if(dp(s,memo,i,j)==true){
            if(j-i+1 > len){
                len=j-i+1;
                start=i;
            }
        }

        return s.substr(start,len);
    }
};