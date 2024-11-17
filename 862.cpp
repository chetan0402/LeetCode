#include<vector>
#include<deque>
#include<climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        deque<int> q;
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            while(!q.empty() && prefix[i]-prefix[q.front()]>=k){
                ans=min(ans,i-q.front());
                q.pop_front();
            }
            while(!q.empty() && prefix[i]<=prefix[q.back()]) q.pop_back();
            q.push_back(i);
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};