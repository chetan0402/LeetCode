#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> cur;
        int right=1;

        cur.push_back(nums[0]);

        vector<int> ans;

        for(int left=0;left+k<=n;left++){
            while(right-left<k){
                if(cur.size() && cur.back()<nums[right]) cur.pop_back();
                else{
                    cur.push_back(nums[right]);
                    right++;
                }
            }
            ans.push_back(cur.front());
            if(cur.front()==nums[left]) cur.pop_front();
        }

        return ans;
    }
};