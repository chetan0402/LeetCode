#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        int min_val=n;
        unordered_map<int,vector<int>> edges;
        for(int i=0;i<n-1;i++){
            edges[i]=vector<int>{i+1};
        }
        for(int i=0;i<queries.size();i++){
            edges[queries[i][0]].push_back(queries[i][1]);
            ans[i]=dp(edges,n);
        }
        return ans;
    }

    int dp(unordered_map<int,vector<int>>&edges,int end){
        vector<int> dp(end);
        dp[end-1]=0;
        for(int i=end-2;i>=0;i--){
            int min_dis=end;
            for(auto&neighbor:edges[i]){
                min_dis=min(min_dis,dp[neighbor]+1);
            }
            dp[i]=min_dis;
        }
        return dp[0];
    }
};