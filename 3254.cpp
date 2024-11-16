#include<vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            int err=false;
            for(int j=0;j<k-1;j++){
                if(nums[i+j]+1!=nums[i+j+1]){
                    ans.push_back(-1);
                    err=true;
                    break;
                }
            }
            if(!err) ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};