#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        vector<int> ans;
        int start=-1;
        for(int i=0;i<n;i++) if(indegree[i]==0){
            start=i;
            break;
        }

        if(start==-1) return ans;

        while(ans.size()<n){
            bool foundAny=false;
            for(int i=0;i<n;i++) if(indegree[i]==0){
                indegree[i]=-1;
                ans.push_back(i);
                foundAny=true;
                for(auto v:adj[i]) indegree[v]--;
            }
            if(!foundAny) return vector<int>();
        }

        return ans;
    }
};