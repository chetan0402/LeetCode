#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cur=0;
        int ans=0;
        vector<int> prefix(nums.size()+1,0);
        prefix[cur]=1;
        for(int i=0;i<nums.size();i++){
            cur+=(nums[i]%2);
            if(cur-k>=0) ans+=prefix[cur-k];
            prefix[cur]++;
        }
        return ans;
    }
};
