#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    bool dfs(int upperLeft,int lowerLeft,vector<int>&colsum,int i){
        if(upperLeft<0 || lowerLeft<0) return false;
        if(i==colsum.size()) return (upperLeft==0 && lowerLeft==0);

        if(colsum[i]==0) return dfs(upperLeft,lowerLeft,colsum,i+1);
        if(colsum[i]==2){
            ans[0][i]=1;
            ans[1][i]=1;
            return dfs(upperLeft-1,lowerLeft-1,colsum,i+1);
        }

        if(upperLeft>lowerLeft){
            ans[0][i]=1;
            ans[1][i]=0;

            return dfs(upperLeft-1,lowerLeft,colsum,i+1);
        }

        ans[0][i]=0;
        ans[1][i]=1;

        return dfs(upperLeft,lowerLeft-1,colsum,i+1);
    }
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        ans=vector<vector<int>>(2,vector<int>(n,0));
        if(dfs(upper,lower,colsum,0)) return ans;

        return {};
    }
};