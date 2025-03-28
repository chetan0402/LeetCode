#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size()==0) return 0;
            unordered_set<int> st(nums.begin(),nums.end());
            int maxLen=1;
            for(auto num:st){
                if(st.count(num-1)) continue;
                int len=1;
                while(st.count(num+1)){
                    len++;
                    num++;
                }
                maxLen=max(maxLen,len);
            }
            return maxLen;
        }
    };