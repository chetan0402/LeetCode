#include<vector>
#include<algorithm>
using namespace std;

const int MOD=1e9+7;

class Solution {
    long long modpow(long long base,long long expo){
        long long result=1;
        base%=MOD;
        while(expo){
            if(expo%2) result=(result*base)%MOD;
            expo>>=1;
            base=(base*base)%MOD;
        }
        return result;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long ans=0;
        int maxIndex=n-1;
        for(int i=0;i<n;i++){
            while(maxIndex>i && nums[i]+nums[maxIndex]>target) maxIndex--;
            if(nums[i]+nums[maxIndex]<=target){
                int permutations=modpow(2,maxIndex-i);
                ans+=permutations;
                ans%=MOD;
            }
        }

        return ans;
    }
};