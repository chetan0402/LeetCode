#include<vector>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long ans=0;
            int start=-1;
            int minI=-1;
            int maxI=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<minK || nums[i]>maxK) start=i;
                if(nums[i]==maxK) maxI=i;
                if(nums[i]==minK) minI=i;
                ans+=max(0,min(minI,maxI)-start);
            }
            return ans;
        }
    };