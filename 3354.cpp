#include<vector>
#include<cmath>
using namespace std;

const vector<int> dirs={1,-1};

class Solution {
    bool valid(vector<int> nums,int cur,int dir){
        while(0<=cur && cur<nums.size()){
            if(nums[cur]==0) cur+=dir;
            else{
                nums[cur]--;
                dir=-dir;
                cur+=dir;
            }
        }
        for(auto num:nums) if(num!=0) return false;
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++) if(nums[i]==0){
            for(auto dir:dirs){
                if(valid(nums,i,dir)) ans++;
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        vector<int> prefix(n+1);
        prefix[0]=0;

        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+nums[i];

        for(int i=0;i<n;i++) if(nums[i]==0){
            int left=prefix[i]-prefix[0];
            int right=prefix[n]-prefix[i];
            
            if(left==right) ans+=2;
            else if(abs(right-left)<=1) ans++;
        }

        return ans;
    }
};