#include<vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rowComp(n,0);
        vector<int> colComp(m,0);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]){
            rowComp[i]++;
            colComp[j]++;
        }
        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]){
            if(rowComp[i]>1 || colComp[j]>1) ans++;
        }
        return ans;
    }
};