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

class SolutionTry2 {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int left=1;
        int right=n-1;

        int pivotIndex=0;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid-1]>arr[mid]){
                pivotIndex=mid;
                break;
            }

            if(arr[mid]<arr[0]) right=mid-1;
            else left=mid+1;
        }

        if(pivotIndex==0){
            left=0;
            right=n-1;
        }else if(target>=arr[0]){
            left=0;
            right=pivotIndex-1;
        }else{
            left=pivotIndex;
            right=n-1;
        }

        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==target) return mid;

            if(arr[mid]<target) left=mid+1;
            else right=mid-1;
        }

        return -1;
    }
};