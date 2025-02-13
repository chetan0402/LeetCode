#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long>,greater<>> pq(nums.begin(),nums.end());
            int steps=0;
            while(pq.top()<k){
                steps++;
                auto small=pq.top();
                pq.pop();
                auto large=pq.top();
                pq.pop();
                pq.push(small*2+large);
            }
            return steps;
        }
    };