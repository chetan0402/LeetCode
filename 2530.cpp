#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--){
            auto cur=pq.top();pq.pop();
            ans+=cur;
            pq.push(ceil(1.0*cur/3));
        }
        return ans;
    }
};
