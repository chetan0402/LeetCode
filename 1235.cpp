#include<vector>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<tuple<int,int,int>> jobs(n);
        for(int i=0;i<n;i++) jobs[i]={startTime[i],endTime[i],profit[i]};

        sort(jobs.begin(),jobs.end(),[](auto&a,auto&b)->bool{
            return get<1>(a) < get<1>(b);
        });

        vector<int> dp(n);
        vector<int> maxdp(n);
        maxdp[0]=dp[0]=get<2>(jobs[0]);

        for(int i=1;i<n;i++){
            auto [start,end,p]=jobs[i];
            dp[i]=p;
            int left=0;
            int right=i-1;
            int found=-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                auto [curstart,curend,_]=jobs[mid];
                if(curend<=start){
                    left=mid+1;
                    found=mid;
                }else right=mid-1;
            }
            if(found!=-1){
                dp[i]=max(dp[i],p+maxdp[found]);
            }
            maxdp[i]=max(dp[i],maxdp[i-1]);
        }

        return maxdp[n-1];
    }
};
