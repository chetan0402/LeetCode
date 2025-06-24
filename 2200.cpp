#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<bool> shouldTake(n,false);
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=max(0,i-k);j<=min(n-1,i+k);j++){
                    shouldTake[j]=true;
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(shouldTake[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};