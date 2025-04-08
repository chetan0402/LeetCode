#include<vector>
#include<unordered_map>
#include<cmath>
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

class SolutionOptimal {
    public:
        int minimumOperations(vector<int>& nums) {
            auto n=nums.size();
            vector<bool> exist(101,false);
            for(int i=n-1;i>=0;i--){
                if(exist[nums[i]]) return ceil(1.0*(i+1)/3);
                exist[nums[i]]=true;
            }
            return 0;
        }
    };