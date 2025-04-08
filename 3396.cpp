#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int,int> cnt;
            for(auto num:nums) cnt[num]++;
            int steps=0;
            int start=0;
            while(nums.size()-start != cnt.size() && start<nums.size()){
                for(int i=0;i<3 and start<nums.size();i++){
                    cnt[nums[start]]--;
                    if(cnt[nums[start]]==0) cnt.erase(nums[start]);
                    start++;
                }
                steps++;
            }
            return steps;
        }
    };