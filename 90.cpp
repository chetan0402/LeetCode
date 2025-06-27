#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        auto backtrack=[&](auto&self,int startPos)->void{
            ans.push_back(temp);
            if(n==startPos) return;
            int prev=INT_MIN;
            for(int i=startPos;i<n;i++){
                if(nums[i]==prev) continue;
                prev=nums[i];
                temp.push_back(nums[i]);
                self(self,i+1);
                temp.pop_back();
            }
        };

        backtrack(backtrack,0);

        return ans;
    }
};