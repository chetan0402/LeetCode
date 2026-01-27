#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<int> cost(n,INT_MAX);
        pq.push({0,0});

        while(pq.size()){
            auto [curCost, node]=pq.top();pq.pop();
            if(curCost>cost[node]) continue;

            for(auto [v, tCost]:adj[node]) if(curCost+tCost<cost[v]){
                cost[v]=curCost+tCost;
                pq.push({cost[v],v});
            }
        }

        return (cost[n-1]==INT_MAX)?-1:cost[n-1];
    }
};
