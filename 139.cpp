#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0]=true;

        unordered_set<string> dict(wordDict.begin(),wordDict.end());

        for(int i=0;i<s.size();i++){
            for(auto&word:dict){
                int start=i-word.size()+1;
                if(start<0) continue;
                if(dp[start] && dict.count(s.substr(start,word.size()))) dp[i+1]=true;
            }
        }

        return dp.back();
    }
};