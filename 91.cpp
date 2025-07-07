#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0') return 0;

        vector<int> memo(n,-1);

        auto dfs=[&](auto&self,int pos)->int{
            if(pos==n) return 1;
            if(memo[pos]!=-1) return memo[pos];
            memo[pos]=0;
            int cur=s[pos]-'0';
            if(cur==0) return memo[pos];
            memo[pos]+=self(self,pos+1);
            if(pos+1==n) return memo[pos];
            cur*=10;
            cur+=s[pos+1]-'0';
            if(cur<=26) return memo[pos]+=self(self,pos+2);
            return memo[pos];
        };

        return dfs(dfs,0);
    }
};