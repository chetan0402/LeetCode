#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int ptr=0;
        int n=events.size();
        int ans=0;
        int day=0;

        priority_queue<int,vector<int>,greater<>> minHeap;

        while(ptr<n || minHeap.size()){
            while(ptr<n && events[ptr][0]<=day) minHeap.push(events[ptr++][1]);
            while(minHeap.size() && minHeap.top()<day) minHeap.pop();
            if(minHeap.size()){
                int end=minHeap.top();
                minHeap.pop();
                ans++;
            }
            day++;
        }

        return ans;
    }
};