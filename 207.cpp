#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        
        for(auto p:prerequisites) adj[p[0]].push_back(p[1]);

        vector<int> color(n,0);

        auto dfs=[&](auto&self,int node)->bool{
            if(color[node]==2) return true;
            if(color[node]==1) return false;
            color[node]=1;
            for(auto next:adj[node]) if(!self(self,next)) return false;
            color[node]=2;
            return true;
        };

        for(int i=0;i<n;i++) if(color[i]==0) if(!dfs(dfs,i)) return false;
        return true;
    }
};