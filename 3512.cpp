#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(auto num:nums) sum+=num;
        return sum%k;
    }
};