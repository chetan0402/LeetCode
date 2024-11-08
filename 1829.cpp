#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int target=(1<<maximumBit)-1;
        int n=nums.size();
        vector<int> ans(n);
        int curXOR=0;
        for(int i=0;i<n;i++){
            curXOR=curXOR^nums[i];
            ans[n-i-1]=target^curXOR;
        }
        return ans;
    }
};