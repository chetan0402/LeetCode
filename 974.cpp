#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> freq;
        // N*modulo
        freq[0]=1;
        int sum=0;
        for(auto num:nums){
            sum+=num;
            ans+=(freq[((sum%k)+k)%k]);
            freq[((sum%k)+k)%k]++;
        }

        return ans;
    }
};