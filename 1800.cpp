#include<vector>
using namespace std;

class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int maxScore=nums[0];
            int score=nums[0];
            int n=nums.size();
            for(int i=1;i<n;i++){
                if(nums[i-1]<nums[i]){
                    score+=nums[i];
                    maxScore=max(maxScore,score);
                }else{
                    score=nums[i];
                }
            }
            return maxScore;
        }
    };