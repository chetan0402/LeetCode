#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<8*sizeof(int);i++){
            int zero=0;
            int one=0;
            for(auto num:nums)
            if(num&(1<<i)) one++;
            else zero++;

            ans+=one*zero;
        }
        return ans;
    }
};
