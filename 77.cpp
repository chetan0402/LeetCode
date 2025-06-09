#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> temp(k,-1);
        auto backtrack=[&](auto&self,int pos)->void{
            if(pos==k){
                ans.push_back(temp);
                return;
            }
            int i;
            if(pos==0) i=1;
            else i=temp[pos-1]+1;
            for(;i<=n;i++){
                temp[pos]=i;
                self(self,pos+1);
                temp[pos]=0;
            }
        };

        backtrack(backtrack,0);

        return ans;
    }
};