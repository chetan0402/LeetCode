#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> pq;
        for(auto num:nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};