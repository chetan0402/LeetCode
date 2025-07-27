#include<vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();

        int hills=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) continue;
            bool leftLowerFound=false;
            bool rightLowerFound=false;
            for(int left=i-1;left>=0;left--){
                if(nums[left]>nums[i]) break;
                if(nums[left]<nums[i]){
                    leftLowerFound=true;
                    break;
                }
            }
            for(int right=i+1;right<n;right++){
                if(nums[right]>nums[i]) break;
                if(nums[right]<nums[i]){
                    rightLowerFound=true;
                    break;
                }
            }
            
            if(leftLowerFound && rightLowerFound) hills++;
        }

        int valley=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) continue;
            bool leftUpperFound=false;
            bool rightUpperFound=false;
            for(int left=i-1;left>=0;left--){
                if(nums[left]<nums[i]) break;
                if(nums[left]>nums[i]){
                    leftUpperFound=true;
                    break;
                }
            }
            for(int right=i+1;right<n;right++){
                if(nums[right]<nums[i]) break;
                if(nums[right]>nums[i]){
                    rightUpperFound=true;
                    break;
                }
            }
            
            if(leftUpperFound && rightUpperFound) valley++;
        }

        return hills+valley;
    }
};