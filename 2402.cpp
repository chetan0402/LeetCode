#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<>> minRoom;
        vector<int> count(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> minEnd;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++) minRoom.push(i);

        int ptr=0;
        long long curtime=meetings[0][0];

        while(ptr<meetings.size()){
            while(minEnd.size() && minEnd.top().first<=curtime){
                auto [_, room]=minEnd.top();minEnd.pop();
                minRoom.push(room);
            }
            if(meetings[ptr][0]>curtime){
                curtime=meetings[ptr][0];
                continue;
            }
            long long duration=meetings[ptr][1]-meetings[ptr][0];
            if(minRoom.size()){
                auto room=minRoom.top();minRoom.pop();
                count[room]++;
                minEnd.push({curtime+duration,room});
                ptr++;
            }else{
                curtime=minEnd.top().first;
            }
        }

        int maxRoom=0;
        for(int i=1;i<n;i++) if(count[i]>count[maxRoom]) maxRoom=i;

        return maxRoom;
    }
};