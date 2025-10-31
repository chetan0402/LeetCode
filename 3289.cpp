#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> seen(nums.size(),false);
        vector<int> ans;
        ans.reserve(2);

        for(auto num:nums)
        if(seen[num]) ans.push_back(num);
        else seen[num]=true;

        return ans;
    }
};