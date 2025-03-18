#include<vector>
using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int bits=0;
            int start=0;
            int len=0;
            for(int end=0;end<nums.size();end++){
                while((bits & nums[end])!=0){
                    bits^=nums[start];
                    start++;
                }
                bits|=nums[end];
                len=max(len,end-start+1);
            }
            return len;
        }
    };