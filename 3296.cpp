#include<vector>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto fn=[&](double s)->bool{
            int height=0;
            for(auto w:workerTimes) height+=floor((-1+sqrt(1+(8.0*s/w)))/2);
            return (height>=mountainHeight);
        };
        int minWorker=*min_element(workerTimes.begin(),workerTimes.end());

        long long ans=-1;
        long long left=1;
        long long right=1LL*minWorker*(mountainHeight)*(mountainHeight+1)/2;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(fn(mid)){
                ans=mid;
                right=mid-1;
            }else left=mid+1;
        }

        return ans;
    }
};
