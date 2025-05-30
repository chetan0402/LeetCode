#include<vector>
#include<queue>
using namespace std;

class Solution {
    void setDist(vector<int>&edges,vector<int>&dist,int node){
        queue<int> q;
        q.push(node);
        dist[node]=0;
        while(q.size()){
            auto cur=q.front();
            q.pop();

            auto next=edges[cur];
            if(next==-1) continue;
            if(dist[next]!=-1) continue;

            dist[next]=dist[cur]+1;
            q.push(next);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto n=edges.size();

        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);

        setDist(edges,dist1,node1);
        setDist(edges,dist2,node2);

        int ans=-1;
        for(int i=0;i<n;i++)
        if(dist1[i]!=-1 && dist2[i]!=-1 && (ans==-1 || max(dist1[ans],dist2[ans])>max(dist1[i],dist2[i]))) ans=i;
        return ans;
    }
};