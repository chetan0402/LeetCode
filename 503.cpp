#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int ptr=0;
        stack<int> s;
        vector<int> ans(n,-1);
        int processing=2*n;
        while(processing--){
            while(s.size() && nums[s.top()]<nums[ptr]){
                auto index=s.top();s.pop();
                ans[index]=nums[ptr];
            }
            s.push(ptr);
            ptr=(ptr+1)%n;
        }
        return ans;
    }
};