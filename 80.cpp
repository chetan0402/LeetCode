#include<vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n=nums.size();
            int k=0;
            for(int i=0;i<n;i++){
                if(k<2 || nums[k-2]!=nums[i]){
                    nums[k++]=nums[i];
                }
            }
            return k;
        }
    };