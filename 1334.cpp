#include<vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        auto LIM=INT_MAX;
        vector<vector<int>> cost(n,vector<int>(n,LIM));
        for(auto&e:edges) cost[e[0]][e[1]]=cost[e[1]][e[0]]=e[2];

        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(cost[i][k]!=LIM & cost[k][j]!=LIM)
        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

        int minCity=n+1;
        int ans=-1;
        for(int i=0;i<n;i++){
            int curCity=0;
            for(int j=0;j<n;j++)
            if(i!=j & cost[i][j]<=distanceThreshold)
            curCity++;

            if(minCity>=curCity){
                minCity=curCity;
                ans=i;
            }
        }

        return ans;
    }
};
