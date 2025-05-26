#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        auto n=colors.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges) adj[edge[0]].push_back(edge[1]);

        int ans=0;

        vector<int> vis(n,0);
        vector<int> topo;
        topo.reserve(n);
        auto dfs=[&](auto&self,int i){
            if(ans==-1) return;
            vis[i]=1;
            for(auto v:adj[i]){
                if(vis[v]==1){
                    ans=-1;
                    return;
                }
                if(vis[v]==0) self(self,v);
            }
            vis[i]=2;
            topo.push_back(i);
        };
        for(int i=0;i<n;i++) if(vis[i]==0){
            dfs(dfs,i);
            if(ans==-1) return -1;
        }

        vector<vector<int>> dp('z'+1,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[colors[i]][i]=1;

        for(int i=0;i<n;i++){
            auto u=topo[i];
            for(auto v:adj[u]){
                dp[colors[u]][u]=max(dp[colors[u]][u],dp[colors[u]][v]+1);
                for(auto chr='a';chr<='z';chr++) if(chr!=colors[u]) dp[chr][u]=max(dp[chr][u],dp[chr][v]);
            }
        }

        for(auto row:dp) for(auto value:row) ans=max(ans,value);
        return ans;
    }
};