#include<vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total=0;
        for(auto num:nums) total+=num;

        int ans=0;
        int current=0;
        for(int i=0;i<nums.size()-1;i++){
            current+=nums[i];
            if((total-current)%2 == current%2) ans++;
        }

        return ans;
    }
};
