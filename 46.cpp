#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        vector<int> temp(n,INT_MAX);

        vector<bool> vis(n,false);

        auto backtrack=[&](auto&self,int pos)->void{
            if(pos==n){
                ans.push_back(temp);
                return;
            }
            for(int i=0;i<n;i++) if(!vis[i]){
                temp[pos]=nums[i];
                vis[i]=true;
                self(self,pos+1);
                temp[pos]=INT_MAX;
                vis[i]=false;
            }
        };

        backtrack(backtrack,0);

        return ans;
    }
};