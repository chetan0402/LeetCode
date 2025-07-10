#include<vector>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];

        int ans=0;
        int prevFirst=0;
        int prevLast=0;

        for(int mid=1;mid<n-1;mid++){
            int leftSum=prefix[mid-1];
            if(leftSum>prefix.back()/2) break;

            int start=max(prevFirst,mid+1);
            int end=n-1;
            int first=-1;
            while(start<=end){
                int right=start+(end-start)/2;
                int midSum=prefix[right-1]-prefix[mid-1];
                int rightSum=prefix.back()-prefix[right-1];
                if(leftSum<=midSum){
                    first=right;
                    end=right-1;
                }else start=right+1;
            }

            if(first==-1) continue;
            prevFirst=first;

            int last=-1;
            start=max(prevLast,first);
            end=n-1;

            while(start<=end){
                int right=start+(end-start+1)/2;
                int midSum=prefix[right-1]-prefix[mid-1];
                int rightSum=prefix.back()-prefix[right-1];
                if(midSum<=rightSum){
                    last=right;
                    start=right+1;
                }else end=right-1;
            }

            if(last==-1) continue;
            prevLast=last;

            int ways=last-first+1;
            ans+=ways;
            ans%=MOD;
        }

        return ans;
    }
};