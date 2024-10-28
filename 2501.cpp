#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        unordered_map<int,int> memo;
        int longest=0;
        for(int i=0;i<nums.size();i++){
            longest=max(longest,dp(nums[i],numSet,memo));
        }
        if(longest<2) return -1;
        else return longest;
    }

    int dp(int current,unordered_set<int>&numSet,unordered_map<int,int>&memo){
        if(memo.count(current)){
            return memo[current];
        }

        long long square = (long long) current * current;
        if (square > 100000) {
            return memo[current] = 1;
        }

        if(numSet.find(square)!=numSet.end()){
            return memo[current]=1+dp(square,numSet,memo);
        }

        return memo[current]=1;
    }
};