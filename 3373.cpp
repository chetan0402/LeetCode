#include<vector>
#include<queue>
using namespace std;

class Solution {
    int getReach(vector<vector<int>>&adj,int node,int parity){
        auto n=adj.size();
        queue<pair<int,int>> q;
        vector<int> vis(n,false);
        
        vis[node]=true;
        q.push({node,0});

        int ans=0;

        while(q.size()){
            auto [node, len]=q.front();
            q.pop();
            if(len%2==parity) ans++;
            for(auto v:adj[node]) if(!vis[v]){
                vis[v]=true;
                q.push({v,len+1});
            }
        }

        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto n=edges1.size()+1;
        auto m=edges2.size()+1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(auto edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto edge:edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        auto maxReach2=max(getReach(adj2,0,1),getReach(adj2,adj2[0][0],1));

        auto set1Reach=getReach(adj1,0,0);
        auto set2Reach=getReach(adj1,adj1[0][0],0);

        queue<pair<int,int>> q;
        vector<int> ans(n,-1);

        q.push({0,0});
        ans[0]=set1Reach+maxReach2;

        while(q.size()){
            auto [node, len]=q.front();
            q.pop();
            for(auto v:adj1[node]) if(ans[v]==-1){
                auto newLen=len+1;
                if(newLen%2) ans[v]=set2Reach+maxReach2;
                else ans[v]=set1Reach+maxReach2;
                q.push({v,newLen});
            }
        }

        return ans;
    }
};