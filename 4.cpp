#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.size()+nums2.size());
        int k=0;
        for(auto num:nums1) nums[k++]=num;
        for(auto num:nums2) nums[k++]=num;

        sort(nums.begin(),nums.end());

        if(nums.size()%2) return nums[nums.size()/2];
        return (1.0*nums[nums.size()/2]+nums[nums.size()/2 -1])/2;
    }
};