#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ptr1=0;
        int ptr2=0;
        int curSum=0;
        int ansLen=INT_MAX;
        while(ptr2<nums.size()){
            curSum+=nums[ptr2];
            while(curSum>=target){
                ansLen=min(ansLen,ptr2-ptr1+1);
                curSum-=nums[ptr1];
                ptr1++;
            }
            ptr2++;
        }
        if(ansLen==INT_MAX) return 0;
        return ansLen;
    }
};