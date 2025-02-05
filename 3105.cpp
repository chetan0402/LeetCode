#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int cur=1;
        int max_cur=1;
        for(int i=0;i<n-1;i++) if(nums[i]<nums[i+1]){
            cur++;
            max_cur=max(max_cur,cur);
        }else cur=1;
        cur=1;
        for(int i=0;i<n-1;i++) if(nums[i]>nums[i+1]){
            cur++;
            max_cur=max(max_cur,cur);
        }else cur=1;
        return max_cur;
    }
};