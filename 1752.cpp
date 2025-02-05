#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool rotated=(nums[0]>=nums[n-1]);
        if(!rotated){
            for(int i=1;i<n;i++) if(nums[i-1]>nums[i]) return false;
        }else{
            bool allowed=true;
            for(int i=1;i<n;i++) if(nums[i-1]>nums[i]){
                if(allowed) allowed=false;
                else return false;
            }
        }
        return true;
    }
};