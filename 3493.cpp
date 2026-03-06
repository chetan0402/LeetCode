#include<vector>
#include<unordered_set>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        size.assign(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    void Union(int u,int v){
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
};

class Solution {
    int intersect(vector<int>&a,vector<int>&b){
        int ans=0;
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                ans++;
                i++;
                j++;
            }else if(a[i]<b[j]) i++;
            else j++;
            while(i>0 && i<a.size() && a[i-1]==a[i]) i++;
            while(j>0 && j<b.size() && b[j-1]==b[j]) j++;
        }

        return ans;
    }
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        DSU dsu(n);

        for(auto&p:properties) sort(p.begin(),p.end());

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(intersect(properties[i],properties[j])>=k)
        dsu.Union(i,j);

        unordered_set<int> roots;
        for(int i=0;i<n;i++) roots.insert(dsu.find(i));

        return roots.size();
    }
};
