#include<vector>
#include<map>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        size.assign(n,1);
    }

    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }

    void Union(int u,int v){
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        if(size[b]>size[a]) swap(a,b);

        parent[b]=a;
        size[a]+=size[b];
    }

    void reset(int a){
        parent[a]=a;
        size[a]=1;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> meeting;

        for(auto&m:meetings) meeting[m[2]].push_back({m[0],m[1]});

        DSU dsu(n);
        dsu.Union(0,firstPerson);

        for(auto&[_,people]:meeting){
            for(auto [p1,p2]:people) dsu.Union(p1,p2);
            for(auto [p1,p2]:people) if(dsu.find(0)!=dsu.find(p1) && dsu.find(0)!=dsu.find(p2)){
                dsu.reset(p1);
                dsu.reset(p2);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++) if(dsu.find(0)==dsu.find(i)) ans.push_back(i);
        return ans;
    }
};
