#include<vector>
using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n=nums.size();
            int l=0;
            int r=n-1;
            while(l<r){
                auto mid=l+(r-l+1)/2;
                if(nums[mid]>=0) r=mid-1;
                else l=mid;
            }
            int negative=(nums[r]!=0)?r+1:0;
            l=0;
            r=n-1;
            while(l<r){
                auto mid=l+(r-l)/2;
                if(nums[mid]<=0) l=mid+1;
                else r=mid;
            }
            int positive=(nums[l]!=0)?n-l:0;
            return max(negative,positive);
        }
    };