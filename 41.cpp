#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size()+2;
        vector<bool> exist(n,false);
        for(auto num:nums) if(num>0 && num<n) exist[num]=true;
        for(int i=1;i<n;i++) if(!exist[i]) return i;
        return -1;
    }
};