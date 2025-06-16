#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right=matrix.size()*matrix[0].size() -1;

        while(left<=right){
            int mid=left+(right-left)/2;
            int row=mid/matrix[0].size(); // i
            int col=mid%matrix[0].size(); // j

            if(matrix[row][col]==target) return true;
            
            if(matrix[row][col]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        return false;
    }
};