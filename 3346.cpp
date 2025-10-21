#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> cnt;
        for(int i=0;i<n;i++) cnt[nums[i]]++;

        int ans=0;

        for(int i=0;i<n;i++){
            int lower=i;
            int left=0;
            int right=i;
            
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]>=nums[i]-k){
                    lower=mid;
                    right=mid-1;
                }else left=mid+1;
            }

            int upper=i;
            left=i;
            right=n-1;

            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            int cur=cnt[nums[i]]+min(numOperations,upper-lower+1-cnt[nums[i]]);
            ans=max(ans,cur);
        }

        for(int i=0;i<n;i++){
            int upper=i;
            int left=i;
            int right=n-1;
            
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+2*k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            ans=max(ans,min(numOperations,upper-i+1));
        }

        return ans;
    }
};

class SolutionSameLogicButOptimized {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> cnt;
        for(int i=0;i<n;i++) cnt[nums[i]]++;

        int ans=0;
        int prevLower=0;
        int prevUpper=0;

        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int lower=prevLower;
            int left=prevLower;
            int right=i;
            
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]>=nums[i]-k){
                    lower=mid;
                    right=mid-1;
                }else left=mid+1;
            }

            int upper=prevUpper;
            left=prevUpper;
            right=n-1;

            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            prevLower=lower;
            prevUpper=upper;
            int cur=cnt[nums[i]]+min(numOperations,upper-lower+1-cnt[nums[i]]);
            ans=max(ans,cur);
        }

        prevUpper=0;

        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int upper=prevUpper;
            int left=prevUpper;
            int right=n-1;
            
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]<=nums[i]+2*k){
                    upper=mid;
                    left=mid+1;
                }else right=mid-1;
            }

            prevUpper=upper;
            ans=max(ans,min(numOperations,upper-i+1));
        }

        return ans;
    }
};