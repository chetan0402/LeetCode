#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int ans=0,cnt=0;
            for(auto num:nums){
                if(cnt==0){
                    ans=num;
                    cnt=1;
                }
                else cnt+=(ans==num)?1:-1;
            }
            return ans;
        }
    };