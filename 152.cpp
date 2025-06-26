#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curMul=1;
        int maxMul=INT_MIN;

        for(int i=0;i<n;i++){
            curMul*=nums[i];
            maxMul=max(maxMul,curMul);
            if(curMul==0) curMul=1;
        }

        curMul=1;
        for(int i=n-1;i>=0;i--){
            curMul*=nums[i];
            maxMul=max(maxMul,curMul);
            if(curMul==0) curMul=1;
        }

        return maxMul;
    }
};