#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int min_num=nums[0];
        for(auto num:nums) min_num=min(min_num,num);

        for(auto num:nums) ans+=num-min_num;
        return ans;
    }
};
