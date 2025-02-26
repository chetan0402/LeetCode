#include<vector>
#include<cmath>
using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            auto n=nums.size();
            int i=0;
            int j=0;
            int cur_sum=0;
            int ans=0;
            while(i<=j && j<n){
                while(j<n && cur_sum+nums[j]>0){
                    cur_sum+=nums[j];
                    j++;
                    ans=max(ans,cur_sum);
                }
                i=j+1;
                j=i;
                cur_sum=0;
            }
            i=0;
            j=0;
            while(i<=j && j<n){
                while(j<n && cur_sum+nums[j]<0){
                    cur_sum+=nums[j];
                    j++;
                    ans=max(ans,abs(cur_sum));
                }
                i=j+1;
                j=i;
                cur_sum=0;
            }
            return ans;
        }
    };