#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            auto n=nums.size();
            unordered_map<int,int> cnt;
            auto ans=0LL;
            int prefix=0;
            cnt[0]=1;
            for(int i=0;i<n;i++){
                prefix+=(nums[i]%modulo==k);
                ans+=cnt[(prefix-k+modulo)%modulo];
                cnt[prefix%modulo]++;
            }
            return ans;
        }
    };