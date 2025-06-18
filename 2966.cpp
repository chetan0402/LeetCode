#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i=0;i+2<n;i+=3){
            if(nums[i+2]-nums[i]>k) return vector<vector<int>>();
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};