#include<vector>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            auto n=nums.size();
            int op=0;
            for(int i=0;i<n-2;i++){
                if(nums[i]==0){
                    op++;
                    for(int k=0;k<3;k++) nums[i+k]=1-nums[i+k];
                }
            }
            if(nums[n-2]==0) return -1;
            if(nums[n-1]==0) return -1;
            return op;
        }
    };