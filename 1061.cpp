#include<vector>
#include<string>
using namespace std;

class Solution {
    vector<int> parent;
    void set(){
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;
    }
    void unite(int u,int v){
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        if(b<a) swap(a,b);
        parent[b]=a;
    }
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        set();
        for(int i=0;i<s1.size();i++) unite(s1[i]-'a',s2[i]-'a');

        for(int i=0;i<baseStr.size();i++) baseStr[i]=find(baseStr[i]-'a')+'a';

        return baseStr;
    }
};