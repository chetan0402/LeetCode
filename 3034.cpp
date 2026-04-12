#include<vector>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int ans=0;
        int n=nums.size();
        int m=p.size();

        for(int i=0;i+m<n;i++){
            bool valid=true;
            for(int j=0;j<m && valid;j++){
                if(p[j]==1) if(nums[i+j]>=nums[i+j+1]) valid=false;
                if(p[j]==0) if(nums[i+j]!=nums[i+j+1]) valid=false;
                if(p[j]==-1) if(nums[i+j]<=nums[i+j+1]) valid=false;
            }
            if(valid) ans++;
        }

        return ans;
    }
};
