#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        auto backtrack=[&](auto&self,int startPos)->void{
            ans.push_back(temp);
            if(n==startPos) return;
            for(int i=startPos;i<n;i++){
                temp.push_back(nums[i]);
                self(self,i+1);
                temp.pop_back();
            }
        };

        backtrack(backtrack,0);

        return ans;
    }
};