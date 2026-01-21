#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) if(nums[i]%2){
            for(int j=0;j<sizeof(int)*8;j++) if((nums[i]&(1<<j))) ans[i]=(nums[i]^(1<<j));
            else break;
        }else ans[i]=-1;
        return ans;
    }
};
