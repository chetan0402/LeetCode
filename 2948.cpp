#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int group=0;
        unordered_map<int,int> num_to_group;
        num_to_group[sorted[0]]=group;
        unordered_map<int,vector<int>> group_nums;
        group_nums[group].push_back(sorted[0]);
        for(int i=1;i<n;i++){
            if(abs(sorted[i]-sorted[i-1])>limit) group++;
            num_to_group[sorted[i]]=group;
            group_nums[group].push_back(sorted[i]);
        }
        for(int i=0;i<n;i++){
            int group=num_to_group[nums[i]];
            nums[i]=group_nums[group][0];
            group_nums[group].erase(group_nums[group].begin());
        }
        return nums;
    }
};