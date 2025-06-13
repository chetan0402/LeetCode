#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        auto fn=[&](int x)->int{
            int i=0,count=0;
            while(i<nums.size()-1){
                if(nums[i+1]-nums[i]<=x){
                    count++;
                    i++;
                }
                i++;
            }
            return count;
        };

        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=l+(r-l)/2;
            if(fn(mid)>=p) r=mid;
            else l=mid+1;
        }
        return r;
    }
};