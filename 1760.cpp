#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid=(right-left)/2 + left;
            int numOp=noOp(nums,mid);
            if(numOp<=maxOperations){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }

    int noOp(vector<int>&nums,int target){
        int n=nums.size();
        int op=0;
        for(int i=0;i<n;i++){
            if(nums[i]>target){
                op+=nums[i]/target;
                if(nums[i]%target==0) op--;
            }
        }
        return op;
    }
};