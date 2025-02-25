#include<vector>
#include<queue>
#include<unordered_map>
#include<tuple>
#include<climits>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> visitied;
    unordered_map<int,int> bobPath;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        auto n=amount.size();
        int maxIncome=INT_MIN;
        adj.resize(n);
        visitied.assign(n,false);
        for(auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(bob,0);
        visitied.assign(n,false);
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});
        while(!q.empty()){
            auto [s, t, income]=q.front();
            if(bobPath.find(s)==bobPath.end() || t<bobPath[s]) income+=amount[s];
            else if(t==bobPath[s]) income+=(amount[s]/2);

            if(adj[s].size()==1 && s!=0) maxIncome=max(maxIncome,income);

            for(auto v:adj[s]){
                if(!visitied[v]) q.push({v,t+1,income});
            }

            visitied[s]=true;
            q.pop();
        }
        return maxIncome;
    }

    bool dfs(int s,int t){
        bobPath[s]=t;
        visitied[s]=true;
        if(s==0) return true;
        for(auto v:adj[s]){
            if(!visitied[v]){
                if(dfs(v,t+1)) return true;
            }
        }
        bobPath.erase(s);
        return false;
    }
};