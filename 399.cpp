#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<int,vector<pair<int,double>>> adj;
        hash<string> hash_str;

        for(int i=0;i<equations.size();i++){
            int u=hash_str(equations[i][0]),v=hash_str(equations[i][1]);
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1/values[i]});
        }

        auto dfs=[&](auto&self,int src,int dest,unordered_map<int,bool>&vis)->double{
            if(src==dest) return 1;
            vis[src]=true;

            double ans=0.0;

            for(auto [node, cost]:adj[src]) if(!vis[node]){
                double temp=self(self,node,dest,vis);
                if(temp!=0){
                    ans=cost*temp;
                    break;
                }
            }

            return ans;
        };
        
        vector<double> ans;

        for(auto q:queries){
            int src=hash_str(q[0]);
            int dest=hash_str(q[1]);
            if(!adj.count(src) || !adj.count(dest)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_map<int,bool> vis;

            double temp=dfs(dfs,src,dest,vis);

            if(temp==0.0) ans.push_back(-1.0);
            else ans.push_back(temp);
        }

        return ans;
    }
};