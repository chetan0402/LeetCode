#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> rowMark(n,0);
        vector<int> colMark(m,0);
        map<int,pair<int,int>> numPos;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) numPos[mat[i][j]]={i,j};
        for(int i=0;i<arr.size();i++){
            auto [row, col] = numPos[arr[i]];
            rowMark[row]++;
            colMark[col]++;
            
            if(rowMark[row]==m || colMark[col]==n) return i;
        }
        return -1;
    }
};