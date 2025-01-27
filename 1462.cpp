#include<vector>
#include<queue>
using namespace std;

class Solution {

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>> edges(n);
        for(const auto&p:prerequisites) edges[p[1]].push_back(p[0]);

        auto bfs=[&](int dest,int source) -> bool{
            queue<int> q;
            vector<bool> visited(n,false);
            q.push(source);
            visited[source]=true;
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                if(dest==cur) return true;
                for(const auto&node:edges[cur]){
                    if(visited[node]) continue;
                    q.push(node);
                    visited[node]=true;
                }
            }
            return false;
        };

        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=bfs(queries[i][0],queries[i][1]);
        }
        return ans;
    }
};