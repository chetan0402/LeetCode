#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int editDistance(string a,string b){
        int ans=0;
        for(int i=0;i<8;i++) if(a[i]!=b[i]) ans++;
        return ans;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        hash<string> hash_str;
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<bank.size();i++) for(int j=i+1;j<bank.size();j++){
            int editDis=editDistance(bank[i],bank[j]);
            if(editDis!=1) continue;
            int u=hash_str(bank[i]);
            int v=hash_str(bank[j]);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool> vis;

        auto dfs=[&](auto&self,int src,int dest)->int{
            if(src==dest) return 0;
            int result=INT_MAX;
            vis[src]=true;
            for(auto v:adj[src]) if(!vis[v]){
                int temp=self(self,v,dest);
                if(temp!=-1) result=min(result,1+temp);
            }
            vis[src]=false;
            return (result==INT_MAX)?-1:result;
        };

        int ans=INT_MAX;
        for(int i=0;i<bank.size();i++){
            int editDis=editDistance(startGene,bank[i]);
            if(editDis<=1){
                vis.clear();
                int tempAns=dfs(dfs,hash_str(bank[i]),hash_str(endGene));
                if(tempAns==-1) continue;
                ans=min(ans,editDis+tempAns);
            }
        }

        return (ans==INT_MAX)?-1:ans;
    }
};