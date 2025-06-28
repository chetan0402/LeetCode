#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }
        vector<bool> selected(nums.size(),false);
        while(pq.size()){
            auto [_, index]=pq.top();
            pq.pop();
            selected[index]=true;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++) if(selected[i]) ans.push_back(nums[i]);
        return ans;
    }
};