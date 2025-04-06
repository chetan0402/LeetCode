#include<vector>
using namespace std;

class Solution {
    void backtract(vector<int>&soln,vector<int>&nums,int i,int&ans){
        if(i>=soln.size()){
            int calcXor=0;
            for(auto num:soln) calcXor^=num;
            ans+=calcXor;
            return;
        };
        soln[i]=nums[i];
        backtract(soln,nums,i+1,ans);
        soln[i]=0;
        backtract(soln,nums,i+1,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        auto n=nums.size();
        int ans=0;
        vector<int> soln(n,0);
        backtract(soln,nums,0,ans);
        return ans;
    }
};