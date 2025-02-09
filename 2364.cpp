#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long n=nums.size();
            unordered_map<long long,long long> offset;
            long long goodpairs=0;
            for(int i=0;i<n;i++) offset[nums[i]-i]++;
            for(auto [key, value]:offset) goodpairs+=((value)*(value-1))/2;
            return ((n)*(n-1))/2-goodpairs;
        }
    };