#include<vector>
#include<unordered_map>
using namespace std;

const int MOD=1e9+7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,int> tcnt;
        for(auto num:nums) tcnt[num]++;
        unordered_map<int,int> cnt;
        for(auto num:nums){
            int target=num<<1;
            long long left=cnt[target];
            long long right=tcnt[target]-(num==target)-cnt[target];
            ans+=(left*right)%MOD;
            ans%=MOD;
            cnt[num]++;
        }
        return ans;
    }
};
