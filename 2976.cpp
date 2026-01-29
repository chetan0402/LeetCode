#include<vector>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long INF=1e15;
        vector<vector<long long>> convert(26,vector<long long>(26,INF));
        for(int i=0;i<cost.size();i++)
        convert[original[i]-'a'][changed[i]-'a']=min(convert[original[i]-'a'][changed[i]-'a'],1LL*cost[i]);
        for(int i=0;i<26;i++) convert[i][i]=0;

        for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        if(convert[i][k]!=INF & convert[k][j]!=INF)
        convert[i][j]=min(convert[i][j],convert[i][k]+convert[k][j]);

        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(convert[source[i]-'a'][target[i]-'a']==INF) return -1;
            ans+=convert[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
