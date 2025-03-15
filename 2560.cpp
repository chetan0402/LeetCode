#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            auto n=nums.size();
    
            auto fn=[&](int maxHouse)->bool{
                int chori=0;
                for(int i=0;i<n;i++) if(nums[i]<=maxHouse){
                    chori++;
                    i++;
                    if(chori==k) return true;
                }
                return (chori>=k);
            };
    
            int l=*min_element(nums.begin(),nums.end());
            int r=*max_element(nums.begin(),nums.end());
            while(l<r){
                auto mid=l+(r-l)/2;
                if(fn(mid)) r=mid;
                else l=mid+1;
            }
            return r;
        }
    };