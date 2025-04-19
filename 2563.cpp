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

class Solution2ndTry {
    long long lessThanEq(vector<int>&nums,int limit){
        int left=0;
        int right=nums.size()-1;
        auto ans=0LL;
        while(left<right){
            if(nums[left]+nums[right]>limit) right--;
            else{
                ans+=(right-left);
                left++;
            }
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lessThanEq(nums,upper)-lessThanEq(nums,lower-1);
    }
};