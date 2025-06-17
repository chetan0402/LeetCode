#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int left=1;
        int right=n-1;

        int k=0;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid-1]>nums[mid]) {
                k=mid;
                break;
            }

            if(left==right) break;

            if(nums[0]<nums[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        if(target<nums[0]){
            left=k;
            right=n-1;
        }else{
            if(k==0) k=n;
            left=0;
            right=k-1;
        }

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;

            if(left==right) break;

            if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        return -1;
    }
};