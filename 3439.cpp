#include<vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps;

        int end=0;

        for(int i=0;i<n;i++){
            gaps.push_back(startTime[i]-end);
            end=endTime[i];
        }

        gaps.push_back(eventTime-endTime.back());

        int sum=0;
        int ans=0;
        for(int right=0;right<gaps.size();right++){
            sum+=gaps[right];
            if(right>=k+1) sum-=gaps[right-k-1];
            ans=max(ans,sum);
        }

        return ans;
    }
};