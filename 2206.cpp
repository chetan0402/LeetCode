#include<vector>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> cnt(500+1,0);
            for(auto num:nums) cnt[num]++;
            for(auto count:cnt) if(count%2) return false;
            return true;
        }
    };