#include<vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> cnt(10e4+1,0);
        for(auto num:nums){
            cnt[num]++;
            if(cnt[num]==2) return num;
        }
        return -1;
    }
};
