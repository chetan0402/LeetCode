#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) continue;
                int top=0;
                int diagonal=0;
                int left=0;
                if(i!=0) top=dp[i-1][j];
                if(i!=0 && j!=0) diagonal=dp[i-1][j-1];
                if(j!=0) left=dp[i][j-1];
                dp[i][j]=1+min(top,min(diagonal,left));
            }
        }
        int total=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++) total+=dp[i][j];
        }
        return total;
    }
};