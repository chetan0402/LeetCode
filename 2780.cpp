#include<vector>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            auto n=nums.size();
            int majority=nums[0];
            int count=0;
            for(auto num:nums){
                if(num==majority) count++;
                else count--;
                if(count==0){
                    majority=num;
                    count=1;
                }
            }
            int leftCount=0;
            int rightCount=0;
            for(auto num:nums) if(num==majority) rightCount++;
            for(int i=0;i<n;i++){
                if(nums[i]==majority){
                    leftCount++;
                    rightCount--;
                }
                if(leftCount>(i+1)/2 && rightCount>(n-i-1)/2) return i;
            }
            return -1;
        }
    };