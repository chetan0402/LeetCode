#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return lowerF(nums,upper+1)-lowerF(nums,lower);
    }

    long long lowerF(vector<int>&nums,int value){
        int left=0;
        int right=nums.size()-1;
        long long result=0;
        while(left<right){
            if(nums[left]+nums[right]<value){
                result+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};