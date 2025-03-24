#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            int lastEnd=0;
            int ans=0;
            for(auto&meeting:meetings){
                if(meeting[0]>lastEnd+1) ans+=meeting[0]-lastEnd-1;
                lastEnd=max(lastEnd,meeting[1]);
            }
            ans+=days-lastEnd;
            return ans;
        }
    };