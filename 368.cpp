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

class SolutionTry2MemoMethod {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> memo(n,-1);
        vector<int> next(n,-1);

        auto dp=[&](auto&self,int pos)->int{
            if(pos>=n) return 0;
            if(memo[pos]!=-1) return memo[pos];
            memo[pos]=1;
            for(int i=pos+1;i<n;i++)
            if(nums[i]%nums[pos]==0){
                int cur=1+self(self,i);
                if(cur>memo[pos]){
                    memo[pos]=cur;
                    next[pos]=i;
                }
            }
            return memo[pos];
        };

        int maxLenI=0;
        dp(dp,0);
        for(int i=1;i<n;i++) if(dp(dp,i)>memo[maxLenI]) maxLenI=i;

        vector<int> ans;
        ans.reserve(memo[maxLenI]);
        for(int i=maxLenI;i!=-1;i=next[i]) ans.push_back(nums[i]);
        return ans;
    }
};

class SolutionTry2TableMethod {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> memo(n,1);
        vector<int> next(n,-1);

        int maxLenI=n-1;

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    int cur=1+memo[j];
                    if(cur>memo[i]){
                        memo[i]=cur;
                        next[i]=j;
                    }
                }
            }
            if(memo[i]>memo[maxLenI]) maxLenI=i;
        }

        vector<int> ans;
        ans.reserve(memo[maxLenI]);
        for(int i=maxLenI;i!=-1;i=next[i]) ans.push_back(nums[i]);
        return ans;
    }
};