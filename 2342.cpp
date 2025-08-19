#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int,int> digitToMax;
    
            auto digits=[](int num)->int{
                int sum=0;
                while(num){
                    sum+=num%10;
                    num/=10;
                }
                return sum;
            };
    
            int ans=-1;
            int n=nums.size();
            for(int i=0;i<n;i++){
                auto cur_digits=digits(nums[i]);
                auto same_digit=digitToMax[cur_digits];
                if(same_digit){
                    ans=max(ans,same_digit+nums[i]);
                    digitToMax[cur_digits]=max(same_digit,nums[i]);
                }else digitToMax[cur_digits]=nums[i];
            }
            return ans;
        }
    };