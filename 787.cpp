#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        k++;
        while(k--){
            vector<int> temp=dist;
            for(auto flight:flights){
                int u=flight[0];
                int v=flight[1];
                int cost=flight[2];
                if(dist[u]==INT_MAX) continue;
                temp[v]=min(temp[v],dist[u]+cost);
            }
            swap(dist,temp);
        }

        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};