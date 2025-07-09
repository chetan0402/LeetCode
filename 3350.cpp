#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> increasingSubarr;

        int len=0;
        int cur=INT_MIN;
        for(auto num:nums){
            if(num<=cur){
                increasingSubarr.push_back(len);
                cur=num;
                len=1;
            }else{
                cur=num;
                len++;
            }
        }

        increasingSubarr.push_back(len);

        int ans=1;
        
        for(auto length:increasingSubarr) ans=max(ans,length/2);

        for(int i=1;i<increasingSubarr.size();i++){
            ans=max(ans,min(increasingSubarr[i-1],increasingSubarr[i]));
        }

        return ans;
    }
};