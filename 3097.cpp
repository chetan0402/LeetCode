#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitSum(32,0);
        int start=0;
        int end=0;
        int minLen=INT_MAX;
        while(end<nums.size()){
            updateBit(bitSum,nums[end],1);
            while(start<=end && arrToNum(bitSum)>=k){
                minLen=min(minLen,end-start+1);
                updateBit(bitSum,nums[start],-1);
                start++;
            }
            end++;
        }
        if(minLen==INT_MAX) return -1;
        return minLen;
    }

    void updateBit(vector<int>&bitSum,int num,int delta){
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                bitSum[i]+=delta;
            }
        }
    }

    int arrToNum(vector<int>&bitSum){
        int num=0;
        for(int i=0;i<bitSum.size();i++){
            if(bitSum[i]) num=num|1<<i;
        }
        return num;
    }
};