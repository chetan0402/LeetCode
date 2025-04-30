#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto num:nums) if(((int)log10(num))%2) ans++;
        return ans;
    }
};