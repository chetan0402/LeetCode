#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int total=0;
        for(int i=0;i<n;i++){
            ans+=(i*nums[i]);
            total+=nums[i];
        }
        int prev=ans;
        for(int i=n-1;i>=1;i--){
            int cur=prev+total-n*nums[i];
            ans=max(ans,cur);
            prev=cur;
        }
        return ans;
    }
};
