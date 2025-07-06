#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                for(int j=n-1;j>=i+1;j--){
                    if(nums[i]<nums[j]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
            }
        }

        reverse(nums.begin(),nums.end());
    }
};