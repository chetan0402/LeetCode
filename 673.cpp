#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> len(n,1);
        vector<int> cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--) if(nums[j]<nums[i]){
                if(len[j]+1>len[i]){
                    len[i]=len[j]+1;
                    cnt[i]=0;
                }

                if(len[j]+1==len[i]) cnt[i]+=cnt[j];
            }
        }

        int maxlen=*max_element(len.begin(),len.end());
        int ans=0;
        for(int i=0;i<n;i++) if(len[i]==maxlen) ans+=cnt[i];
        return ans;
    }
};
