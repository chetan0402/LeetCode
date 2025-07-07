#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> stopToBuses;

        for(int i=0;i<n;i++){
            for(auto stop:routes[i]){
                stopToBuses[stop].push_back(i);
            }
        }

        vector<vector<int>> adj(n);

        for(auto&[_, buses]:stopToBuses){
            for(int i=0;i<buses.size();i++){
                for(int j=i+1;j<buses.size();j++){
                    adj[buses[i]].push_back(buses[j]);
                    adj[buses[j]].push_back(buses[i]);
                }
            }
        }

        queue<pair<int,int>> q;
        vector<bool> vis(n,false);
        for(auto bus:stopToBuses[source]){
            q.push({bus,1});
            vis[bus]=true;
        }

        unordered_set<int> finish(stopToBuses[target].begin(),stopToBuses[target].end());

        while(q.size()){
            auto [bus, changes]=q.front();
            q.pop();
            if(finish.count(bus)) return changes;

            for(auto v:adj[bus]) if(!vis[v]) {
                q.push({v,changes+1});
                vis[v]=true;
            }
        }

        return -1;
    }
};