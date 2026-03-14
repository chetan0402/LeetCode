#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=1;
        int left=0;
        deque<int> maxV;
        deque<int> minV;
        for(int right=0;right<n;right++){
            while(maxV.size() && maxV.back()<nums[right]) maxV.pop_back();
            maxV.push_back(nums[right]);
            while(minV.size() && minV.back()>nums[right]) minV.pop_back();
            minV.push_back(nums[right]);

            while(maxV.front()-minV.front()>limit){
                if(maxV.front()==nums[left]) maxV.pop_front();
                if(minV.front()==nums[left]) minV.pop_front();
                left++;
            }
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};
