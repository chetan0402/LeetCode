#include<vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i+1<n && nums[i+1]>nums[i]) i++;
        if(i==0 | i==n) return false;
        int prev=i;
        while(i+1<n && nums[i+1]<nums[i]) i++;
        if(i==prev | i==n) return false;
        prev=i;
        while(i+1<n && nums[i+1]>nums[i]) i++;
        if(i==prev) return false;
        return (i==n-1);
    }
};
