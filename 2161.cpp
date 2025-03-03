#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> ans;
            ans.reserve(nums.size());
            for(auto num:nums) if(num<pivot) ans.push_back(num);
            for(auto num:nums) if(num==pivot) ans.push_back(num);
            for(auto num:nums) if(num>pivot) ans.push_back(num);
            return ans;
        }
    };