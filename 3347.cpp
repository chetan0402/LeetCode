#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        unordered_map<long long,long long> cnt;
        for(long long i=0;i<n;i++) cnt[nums[i]]++;

        long long ans=0;
        long long prevLower=0;
        long long prevUpper=0;

        for(long long i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            long long lower=prevLower;
            long long left=prevLower;
            long long right=i;
            
            while(left<=right){
                long long mid=left+(right-left)/2;
                if(nums[mid]>=nums[i]-k){
                    lower=mid;
                    right=mid-1;
                }else left=mid+1;
            }

            long long upper=prevUpper;
            left=prevUpper;
            right=n-1;

            while(left<=right){
                long long mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            prevLower=lower;
            prevUpper=upper;
            long long cur=cnt[nums[i]]+min(1LL*numOperations,upper-lower+1-cnt[nums[i]]);
            ans=max(ans,cur);
        }

        prevUpper=0;

        for(long long i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            long long upper=prevUpper;
            long long left=prevUpper;
            long long right=n-1;
            
            while(left<=right){
                long long mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+2LL*k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            prevUpper=upper;
            ans=max(ans,min(1LL*numOperations,upper-i+1));
        }

        return ans;
    }
};