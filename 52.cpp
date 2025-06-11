#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count=0;

        vector<int> ans(n,-1);

        auto backtrack=[&](auto&self,int pos)->void{
            if(pos==n){
                count++;
                return;
            }
            for(int i=0;i<n;i++){
                bool valid=true;
                for(int j=0;j<pos;j++){
                    if(ans[j]==i || abs(ans[j]-i)==abs(j-pos)){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    ans[pos]=i;
                    self(self,pos+1);
                }
            }
        };

        backtrack(backtrack,0);

        return count;
    }
};