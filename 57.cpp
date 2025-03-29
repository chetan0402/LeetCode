#include<vector>
#include<climits>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            auto n=intervals.size();
            vector<vector<int>> ans;
            int start=-1;
            int end=newInterval[1];
            int i=0;
            while(i<n && intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
            }
            start=min(((i<n)?intervals[i][0]:INT_MAX),newInterval[0]);
            while(i<n && intervals[i][0]<=newInterval[1]){
                end=max(intervals[i][1],end);
                i++;
            }
            ans.push_back({start,end});
            while(i<n) ans.push_back(intervals[i++]);
            return ans;
        }
    };