#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> numToI;
            for(int i=0;i<nums.size();i++){
                auto it=numToI.find(target-nums[i]);
                if(it!=numToI.end()) return {it->second,i};
                numToI[nums[i]]=i;
            }
            return {-1,-1};
        }
    };