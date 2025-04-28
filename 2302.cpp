#include<vector>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            auto n=nums.size();
            long long ans=0;
            int left=0;
            long long sum=0;
            for(int right=0;right<n;right++){
                sum+=nums[right];
                while(left<n && sum*(right-left+1)>=k){
                    sum-=nums[left];
                    left++;
                }
                if(sum*(right-left+1)<k) ans+=(right-left+1);
            }
            return ans;
        }
    };