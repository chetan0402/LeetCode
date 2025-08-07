#include<vector>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();

        int profit=0;

        for(int i=0;i<n;i++){
            profit+=fruits[i][i];
            fruits[i][i]=0;
        }

        vector<vector<int>> best(n,vector<int>(n,0));

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(i==j) break;
                if(i+j<n-1) break;

                if(j-1>=i+1 && j-1>=0 && i+1<n) best[i][j]=fruits[i][j]+best[i+1][j-1];
                if(j>=i+1 && i+1<n) best[i][j]=max(best[i][j],fruits[i][j]+best[i+1][j]);
                if(j+1>=i+1 && j+1<n && i+1<n) best[i][j]=max(best[i][j],fruits[i][j]+best[i+1][j+1]);
            }
        }

        for(int j=n-2;j>=0;j--){
            for(int i=n-1;i>=j;i--){
                if(i==j) break;
                if(i+j<n-1) break;

                if(j+1<=i-1 && j+1<n && i-1>=0) best[i][j]=fruits[i][j]+best[i-1][j+1];
                if(j+1<=i && j+1<n) best[i][j]=max(best[i][j],fruits[i][j]+best[i][j+1]);
                if(j+1<=i+1 && j+1<n && i+1<n) best[i][j]=max(best[i][j],fruits[i][j]+best[i+1][j+1]);
            }
        }

        return profit+best[0][n-1]+best[n-1][0];
    }
};