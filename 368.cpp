#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    pair<int,int> dp(int i,vector<int>&nums,vector<pair<int,int>>&memo){
        auto n=nums.size();
        if(i>=n) return {0,-1};
        auto [lenOfSeq,nextI]=memo[i];
        if(lenOfSeq!=-1) return memo[i];
        int maximumLength=0;
        int maximumLengthIndex=-1;
        for(int j=i+1;j<n;j++){
            if(nums[j]%nums[i]!=0) continue;
            auto [curLen,_]=dp(j,nums,memo);
            if(curLen>maximumLength){
                maximumLength=curLen;
                maximumLengthIndex=j;
            }
        }
        return memo[i]={1+maximumLength,maximumLengthIndex};
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        auto n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> memo(n,{-1,-1});
        int maximumLength=0;
        int maximumLengthIndex=0;
        for(int i=0;i<n;i++){
            auto [curLen,curIndex]=dp(i,nums,memo);
            if(curLen>maximumLength){
                maximumLength=curLen;
                maximumLengthIndex=i;
            }
        }
        vector<int> ans;
        while(maximumLengthIndex<n && maximumLengthIndex>=0){
            ans.push_back(nums[maximumLengthIndex]);
            auto [_,nextIndex]=dp(maximumLengthIndex,nums,memo);
            maximumLengthIndex=nextIndex;
        }
        return ans;
    }
};