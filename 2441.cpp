#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> exists(nums.begin(),nums.end());
        int largest=-1;
        for(int i=0;i<nums.size();i++){
            if(exists.find(-nums[i])!=exists.end()) largest=max(largest,nums[i]);
        }
        return largest;
    }
};