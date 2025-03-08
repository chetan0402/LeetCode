#include<vector>
using namespace std;

const vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto n=matrix.size();
        auto m=matrix[0].size();
        vector<vector<bool>> seen(n,vector<bool>(m,false));
        vector<int> ans={matrix[0][0]};
        seen[0][0]=true;
        int i=0;
        int j=0;
        int ptr=0;
        while(ans.size()!=n*m){
            auto [dx,dy]=dirs[ptr];
            if(i+dx>=0 && i+dx<n && j+dy>=0 && j+dy<m && !seen[i+dx][j+dy]){
                i+=dx;
                j+=dy;
                ans.push_back(matrix[i][j]);
                seen[i][j]=true;
            }else{
                ptr++;
                ptr%=4;
            }
        }
        return ans;
    }
};