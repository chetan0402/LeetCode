#include<vector>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<vector<int>> emp_to_favs(n);
        vector<bool> visited(n,false);
        vector<int> memo(n,-1);

        for(int i=0;i<n;i++) emp_to_favs[favorite[i]].push_back(i);

        int two_way=0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(favorite[favorite[i]]==i){
                visited[i]=true;
                visited[favorite[i]]=true;
                two_way+=dfs(i,visited,emp_to_favs,memo)+dfs(favorite[i],visited,emp_to_favs,memo);
            }
        }

        int longcycle=0;
        vector<bool> looped(n,false);
        vector<int> dis(n,1);
        for(int i=0;i<n;i++){
            if(visited[i] || looped[i]) continue;
            visited[i]=true;
            int cur=i;
            vector<bool> tempVisited(n,false);
            while(true){
                int cur_next=favorite[cur];
                if(tempVisited[cur_next]){
                    longcycle=max(longcycle,dis[cur]-dis[cur_next]+1);
                    break;
                }
                tempVisited[cur_next]=true;
                dis[cur_next]=dis[cur]+1;
                looped[cur]=true;
                cur=cur_next;
            }
        }

        return max(longcycle,two_way);
    }

    int dfs(int root,vector<bool>&visited,vector<vector<int>>&emp_to_favs,vector<int>&memo){
        if(memo[root]!=-1) return memo[root];
        int depth=1;
        for(const auto fav:emp_to_favs[root]){
            if(visited[fav]) continue;
            visited[fav]=true;
            depth=max(depth,1+dfs(fav,visited,emp_to_favs,memo));
        }
        return memo[root]=depth;
    }
};