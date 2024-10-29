#include<vector>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n=nums.size();
        vector<bool> prefix(n);
        vector<bool> suffix(n);

        prefix[0]=true;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1] && (nums[i] > nums[i-1]);
        }

        suffix[n-1]=true;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1] && (nums[i+1] > nums[i]);
        }

        if(prefix[n-1]) return true;
        if(n>1 && suffix[1]) return true;
        if(n>1 && prefix[n-2]) return true;
        for(int i=1;i<n-1;i++){
            if(prefix[i-1] && suffix[i+1] && nums[i-1]<nums[i+1]) return true;
        }
        return false;
    }
};