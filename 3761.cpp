#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    inline int reverse(int num){
        int ans=0;
        while(num){
            ans=ans*10+(num%10);
            num/=10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> seen;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(seen.count(nums[i])) ans=min(ans,i-seen[nums[i]]);
            seen[reverse(nums[i])]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
