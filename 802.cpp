#include<vector>
using namespace std;

class Solution {
    int UNVISITED=0;
    int TERMINAL=1;
    int SAFE=2;
    int VISITED=3;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> memo(n,UNVISITED);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dp(i,graph,memo)==TERMINAL || dp(i,graph,memo)==SAFE) ans.push_back(i);
        }
        return ans;
    }

    int dp(int source,vector<vector<int>>&graph,vector<int>&memo){
        if(memo[source]!=UNVISITED) return memo[source];
        memo[source]=VISITED;
        if(graph[source].size()==0) return memo[source]=TERMINAL;
        for(auto&v:graph[source]){
            if(dp(v,graph,memo)==VISITED) return memo[source]=VISITED;
        }
        return memo[source]=SAFE;
    }
};