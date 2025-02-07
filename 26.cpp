#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        int cur=INT_MIN;
        for(int i=0;i<n;i++) if(nums[i]>cur){
            cur=nums[k++]=nums[i];
        }
        return k;
    }
};