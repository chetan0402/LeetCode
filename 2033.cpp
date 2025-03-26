#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            auto m=grid.size();
            auto n=grid[0].size();
            vector<int> nums;
            nums.reserve(m*n);
            for(auto&row:grid) for(auto num:row) nums.push_back(num);
            nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
            int median=nums[nums.size()/2];
            int ans=0;
            for(auto&row:grid) for(auto num:row){
                if(num%x!=median%x) return -1;
                ans+=abs(num-median)/x;
            }
            return ans;
        }
    };