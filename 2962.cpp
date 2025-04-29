#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            auto n=nums.size();
            int targetElement=*max_element(nums.begin(),nums.end());
            int count=0;
            int left=0;
            long long ans=0;
            for(int right=0;right<n;right++){
                auto add=nums[right];
                if(add==targetElement) count++;
                while(count>k || (count==k && nums[left]!=targetElement)){
                    auto remove=nums[left];
                    if(remove==targetElement) count--;
                    left++;
                }
                if(count==k) ans+=left+1;
            }
            return ans;
        }
    };