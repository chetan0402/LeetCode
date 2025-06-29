#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        for(int i=0;i<n;i++) if(nums[i]==0){
            swap(nums[zero],nums[i]);
            zero++;
        }
        int one=zero;
        for(int i=one;i<n;i++) if(nums[i]==1){
            swap(nums[one],nums[i]);
            one++;
        }
    }
};