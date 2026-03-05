#include<vector>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<bool> marked(n,false);

        int ans=0;
        int j=n/2;

        for(int i=0;i<n;i++) if(!marked[i]) {
            int target=2*nums[i];
            while(j<n && target>nums[j]) j++;
            if(j<n && marked[j]) j++;
            if(j==n) break;
            marked[i]=marked[j]=true;
            ans++;
        }

        return 2*ans;
    }
};
