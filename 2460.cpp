#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            auto n=nums.size();
            for(int i=0;i+1<n;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
            }
            int k=0;
            for(int i=0;i<n;i++) if(nums[i]!=0) nums[k++]=nums[i];
            while(k<n) nums[k++]=0;
            return nums;
        }
    };