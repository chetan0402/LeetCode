#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        // distance, count
        vector<pair<long long,long long>> dis(n,{LLONG_MAX,1});
        // weight, vertex
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        pq.push({0,0});
        dis[0]={0,1};
        while(!pq.empty()){
            auto [weight, vertex]=pq.top();
            pq.pop();
            if(weight>dis[vertex].first) continue;
            for(auto [v, w]:adj[vertex]){
                if(dis[vertex].first+w<dis[v].first){
                    dis[v]={dis[vertex].first+w,dis[vertex].second};
                    pq.push({dis[v].first,v});
                }else if(dis[vertex].first+w==dis[v].first){
                    dis[v].second=(dis[v].second+dis[vertex].second)%MOD;
                }
            }
        }
        return dis[n-1].second;
    }
};