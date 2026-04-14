#include<vector>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans=0;
        vector<int> paired(n);
        for(auto&pair:pairs){
            paired[pair[0]]=pair[1];
            paired[pair[1]]=pair[0];
        }

        vector<vector<int>> rprefs(n,vector<int>(n));

        for(int i=0;i<n;i++) for(int j=0;j<n-1;j++) rprefs[i][preferences[i][j]]=j;

        for(int x=0;x<n;x++){
            auto y=paired[x];
            for(int u=0;u<n;u++){
                if(u==x | u==y) continue;
                auto v=paired[u];

                if(rprefs[x][u]<rprefs[x][y] & rprefs[u][x]<rprefs[u][v]){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
