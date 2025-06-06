#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
    int distance(string a,string b){
        int result=0;
        for(int i=0;i<a.size();i++) if(a[i]!=b[i]) result++;
        return result;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        hash<string> hash_str;
        unordered_map<int,vector<int>> adj;
        int startHash=hash_str(beginWord);
        int endHash=hash_str(endWord);
        
        for(int i=0;i<wordList.size();i++) for(int j=i+1;j<wordList.size();j++)
        if(distance(wordList[i],wordList[j])==1){
            int u=hash_str(wordList[i]);
            int v=hash_str(wordList[j]);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto word:wordList) if(distance(beginWord,word)==1) adj[startHash].push_back(hash_str(word));

        queue<pair<int,int>> q;
        q.push({startHash,1});

        unordered_map<int,bool> vis;
        vis[startHash]=true;

        while(q.size()){
            auto [node, distance]=q.front();
            q.pop();

            if(node==endHash) return distance;

            for(auto v:adj[node]) if(!vis[v]){
                vis[v]=true;
                q.push({v,distance+1});
            }
        }

        return 0;
    }
};