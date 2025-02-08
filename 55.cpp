#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            if(n==1) return true;
            int max_reached=0;
            for(int i=0;i<n;i++){
                if(max_reached>=n-1) return true;
                if(max_reached==i && nums[i]==0) return false;
                else max_reached=max(max_reached,i+nums[i]);
            }
            return true;
        }
    };