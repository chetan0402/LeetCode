#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> seen;
        seen.insert(0);
        int cnt=0;
        int sum=0;
        for(auto num:nums){
            sum+=num;
            if(seen.count(sum-target)){
                cnt++;
                sum=0;
                seen.clear();
                seen.insert(0);
            }else seen.insert(sum);
        }
        return cnt;
    }
};
