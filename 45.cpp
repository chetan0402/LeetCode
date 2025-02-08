#include<vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int n=nums.size();
            int furthest=0;
            int ans=0;
            int level_end=0;
            for(int i=0;i<n-1;i++){
                furthest=max(furthest,i+nums[i]);
                if(level_end==i){
                    ans++;
                    level_end=furthest;
                }
            }
            return ans;
        }
    };