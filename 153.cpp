#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=1;
        int right=nums.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid-1]>nums[mid]) return nums[mid];

            if(nums[0]<nums[mid]) left=mid+1;
            else right=mid-1;
        }

        return nums[0];
    }
};