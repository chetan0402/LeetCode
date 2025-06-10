#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> values(candidates.size(),0);

        auto backtrack=[&](auto&self,int pos,int curSum)->void{
            if(pos==candidates.size() || curSum==target){
                if(curSum!=target) return;
                vector<int> temp;
                for(int i=0;i<values.size();i++) for(int j=0;j<values[i];j++) temp.push_back(candidates[i]);
                ans.push_back(temp);
                return;
            }
            if(curSum>target) return;

            for(int i=0;i<=(target-curSum)/candidates[pos];i++){
                values[pos]=i;
                self(self,pos+1,curSum+candidates[pos]*i);
                values[pos]=0;
            }
        };

        backtrack(backtrack,0,0);

        return ans;
    }
};