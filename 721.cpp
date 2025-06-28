#include<vector>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

class DSU{
    public:
    vector<int> size;
    vector<int> parent;
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);
        unordered_map<string,int> emailToI;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(emailToI.count(email)){
                    dsu.Union(emailToI[email],i);
                }else emailToI[email]=i;
            }
        }

        unordered_map<int,pair<string,set<string>>> parentToAccount;

        for(int i=0;i<n;i++){
            int parent=dsu.find(i);
            parentToAccount[parent].first=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++)
            parentToAccount[parent].second.insert(accounts[i][j]);
        }

        vector<vector<string>> ans;

        for(auto&pta:parentToAccount){
            auto [name, emails]=pta.second;
            vector<string> temp={name};
            for(auto email:emails) temp.emplace_back(email);
            ans.push_back(temp);
        }

        return ans;
    }
};