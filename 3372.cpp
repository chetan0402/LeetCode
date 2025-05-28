#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
    void setReach(vector<vector<int>>&adj,vector<int>&reach,int k){
        auto n=adj.size();
        if(k<0){
            for(int i=0;i<n;i++) reach[i]=0;
            return;
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            vis[i]=true;
            queue<pair<int,int>> q;
            q.push({i,0});
            reach[i]=1;
            while(q.size()){
                auto [node, len]=q.front();
                q.pop();
                if(len>=k) continue;
                for(auto v:adj[node]) if(!vis[v]){
                    reach[i]++;
                    q.push({v,len+1});
                    vis[v]=true;
                }
            }
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        auto n=edges1.size()+1;
        auto m=edges2.size()+1;
        vector<int> reach1(n);
        vector<int> reach2(m);
        
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

        setReach(adj1,reach1,k);
        setReach(adj2,reach2,k-1);

        auto maxReach2=*max_element(reach2.begin(),reach2.end());
        
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]=reach1[i]+maxReach2;
        return ans;
    }
};