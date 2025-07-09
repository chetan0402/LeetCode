#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> temp;
        auto backtrack=[&](auto&self,int row)->void{
            if(row==n){
                vector<string> soln(n,string(n,'.'));
                for(int i=0;i<n;i++) soln[i][temp[i]]='Q';
                ans.push_back(soln);
                return;
            }
            for(int col=0;col<n;col++){
                bool valid=true;
                for(int i=0;i<temp.size();i++) if(temp[i]==col || (i-temp[i])==(row-col) || (i+temp[i]==(row+col))) valid=false;
                if(valid){
                    temp.push_back(col);
                    self(self,row+1);
                    temp.pop_back();
                }
            }
        };

        backtrack(backtrack,0);

        return ans;
    }
};