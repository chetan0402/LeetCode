#include<vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        int left=0;
        int right=0;

        while(left<n && right<n){
            while(left<n && nums[left]!=0) left++;
            right=left;
            while(right<n && nums[right]==0) right++;
            long long len=right-left;
            ans+=(len)*(len+1)/2;

            left=right;
        }

        return ans;
    }
};


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        int i=0;

        while(i<n){
            while(i<n && nums[i]!=0) i++;
            long long len=0;
            while(i<n && nums[i]==0){
                i++;
                len++;
            }
            ans+=(len)*(len+1)/2;
        }

        return ans;
    }
};