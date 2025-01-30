#include<vector>
#include<queue>
using namespace std;

class Solution {
    int GROUP_1=0;
    int GROUP_2=1;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> state(n,0);
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            visited[i]=true;
            state[i]=GROUP_1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                visited[cur]=true;
                for(auto node:graph[cur]){
                    if(visited[node]){
                        if(state[node]==state[cur]) return false;
                    }else{
                        q.push(node);
                        state[node]=1-state[cur];
                    }
                }
            }
        }
        return true;
    }
};