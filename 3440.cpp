#include<vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gaps;

        int end=0;
        for(int i=0;i<n;i++){
            gaps.push_back(startTime[i]-end);
            end=endTime[i];
        }

        gaps.push_back(eventTime-end);

        int ans=0;

        for(int i=1;i<gaps.size();i++){
            ans=max(ans,gaps[i-1]+gaps[i]);
        }

        vector<int> prefixMax(gaps.size());
        prefixMax[0]=gaps[0];
        for(int i=1;i<gaps.size();i++) prefixMax[i]=max(prefixMax[i-1],gaps[i]);

        vector<int> suffixMax(gaps.size());
        suffixMax.back()=gaps.back();
        for(int i=gaps.size()-2;i>=0;i--) suffixMax[i]=max(suffixMax[i+1],gaps[i]);

        for(int i=0;i<n;i++){
            int leftGap=gaps[i];
            int rightGap=gaps[i+1];
            int interval=endTime[i]-startTime[i];

            if((i>0 && prefixMax[i-1]>=interval) || 
            (i+2<suffixMax.size() && suffixMax[i+2]>=interval)) ans=max(ans,leftGap+rightGap+interval);
        }

        return ans;
    }
};