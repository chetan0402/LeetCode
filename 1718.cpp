#include<vector>
using namespace std;

class Solution {
    bool backtrack(int i,vector<int>&ans,vector<bool>&used,int end){
        if(i==ans.size()) return true;
        if(ans[i]!=0) return backtrack(i+1,ans,used,end);
        for(int num=end;num>=1;num--){
            if(used[num]) continue;
            used[num]=true;
            ans[i]=num;
            if(num==1){
                if(backtrack(i+1,ans,used,end)) return true;
            }else if(i+num<ans.size() && ans[i+num]==0){
                ans[i+num]=num;
                if(backtrack(i+1,ans,used,end)) return true;
                ans[i+num]=0;
            }
            ans[i]=0;
            used[num]=false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n*2-1,0);
        vector<bool> used(n+1,false);
        backtrack(0,ans,used,n);
        return ans;
    }
};