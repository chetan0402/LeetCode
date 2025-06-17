#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;

        int start=-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target){
                start=mid;
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        if(start==-1) return {-1,-1};

        left=start;
        right=n-1;

        int end=start;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target){
                end=mid;
                left=mid+1;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        return {start,end};
    }
};