#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            auto n=nums.size();
            vector<string> ans;
            int start=0;
            int end=0;
            while(start<=end && end<n){
                while(end+1<n && nums[end]+1==nums[end+1]) end++;
                if(start==end) ans.push_back(to_string(nums[start]));
                else ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                start=end+1;
                end=start;
            }
            return ans;
        }
    };