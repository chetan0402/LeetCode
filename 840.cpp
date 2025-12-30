#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i+2<n;i++) for(int j=0;j+2<m;j++){
            auto top=i;
            auto bottom=i+2;
            auto left=j;
            auto right=j+2;

            bool ok=true;
            unordered_set<int> unique;
            int sum=15;
            for(int row=top;row<=bottom and ok;row++){
                int cursum=0;
                for(int col=left;col<=right;col++){
                    cursum+=grid[row][col];
                    unique.insert(grid[row][col]);
                }
                if(cursum!=sum){
                    ok=false;
                    break;
                }
            }
            if(unique.size()!=9) ok=false;
            for(int num=1;num<=9 and ok;num++) if(!unique.count(num)) ok=false;
            for(int col=left;col<=right and ok;col++){
                int cursum=0;
                for(int row=top;row<=bottom;row++) cursum+=grid[row][col];
                if(cursum!=sum){
                    ok=false;
                    break;
                }
            }
            int sumDia1=0;
            int sumDia2=0;
            for(int k=0;k<=2 and ok;k++){
                sumDia1+=grid[top+k][left+k];
                sumDia2+=grid[top+k][right-k];
            }
            if(sumDia1!=sum) ok=false;
            if(sumDia2!=sum) ok=false;
            if(ok) ans++;
        }
        return ans;
    }
};