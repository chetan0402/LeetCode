#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int dfs(vector<vector<int>>&events,int i,int k,vector<vector<int>>&memo){
        int n=events.size();
        if(i>=n) return 0;
        if(k==0) return 0;
        if(memo[i][k]!=-1) return memo[i][k];

        memo[i][k]=dfs(events,i+1,k,memo);

        int left=i+1;
        int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(events[mid][0]<=events[i][1]){
                left=mid+1;
            }else right=mid;
        }

        memo[i][k]=max(memo[i][k],events[i][2]+dfs(events,right,k-1,memo));

        return memo[i][k];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> memo(n,vector<int>(k+1,-1));

        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dfs(events,i,k,memo));

        return ans;
    }
};