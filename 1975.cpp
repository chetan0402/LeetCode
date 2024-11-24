#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int min_abs=INT_MAX;
        int neg_count=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) neg_count++;
                min_abs=min(min_abs,abs(matrix[i][j]));
            }
        }

        if(neg_count%2) sum-= 2*min_abs;
        return sum;
    }
};