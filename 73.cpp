#include<vector>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            auto n=matrix.size();
            auto m=matrix[0].size();
            bool firstRow=false;
            bool firstCol=false;
            for(int i=0;i<n;i++) if(matrix[i][0]==0){
                firstRow=true;
                break;
            }
            for(int j=0;j<m;j++) if(matrix[0][j]==0){
                firstCol=true;
                break;
            }
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
            for(int i=1;i<n;i++) if(matrix[i][0]==0) for(int j=0;j<m;j++) matrix[i][j]=0;
            for(int j=1;j<m;j++) if(matrix[0][j]==0) for(int i=0;i<n;i++) matrix[i][j]=0;
            if(firstRow) for(int i=0;i<n;i++) matrix[i][0]=0;
            if(firstCol) for(int j=0;j<m;j++) matrix[0][j]=0;
        }
    };