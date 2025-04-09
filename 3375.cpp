#include<vector>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            vector<int> cnt(101,0);
            for(auto num:nums){
                cnt[num]++;
                if(num<k) return -1;
            }
            int unique=0;
            for(auto freq:cnt) if(freq) unique++;
            return unique-(cnt[k]>0);
        }
    };