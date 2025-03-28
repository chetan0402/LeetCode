#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int> numToI;
            for(int i=0;i<nums.size();i++){
                if(numToI.find(nums[i])!=numToI.end() && i-numToI[nums[i]]<=k) return true;
                numToI[nums[i]]=i;
            }
            return false;
        }
    };