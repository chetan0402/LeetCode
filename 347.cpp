#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto num:nums) freq[num]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

        for(auto [number, frequency]:freq){
            pq.push({frequency,number});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;
        while(pq.size()){
            auto [_, num]=pq.top();
            pq.pop();
            ans.push_back(num);
        }

        return ans;
    }
};