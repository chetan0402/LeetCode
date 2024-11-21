#include<vector>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>info(m,vector<int>(n,1));
        int ans=m*n;
        for(const auto&wall_cord:walls){
            info[wall_cord[0]][wall_cord[1]]=-1;
            ans--;
        }
        for(const auto&guard:guards){
            info[guard[0]][guard[1]]=2;
            ans--;
        }
        const vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        for(const auto&guard:guards){
            for(const auto&dir:dirs){
                int i=guard[0]+dir.first;
                int j=guard[1]+dir.second;
                while(i>=0 && i<m && j>=0 && j<n){
                    if(info[i][j]==-1 || info[i][j]==2) break;
                    if(info[i][j]==1){
                        ans--;
                        info[i][j]=0;
                    }
                    i+=dir.first;
                    j+=dir.second;
                }
            }
        }
        return ans;
    }
};