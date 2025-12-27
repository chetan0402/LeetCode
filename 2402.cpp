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

class Solution2 {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> cnt(n,0);

        priority_queue<int,vector<int>,greater<>> avaliable;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> busy;
        for(int i=0;i<n;i++) busy.push({0,i});

        for(auto&m:meetings){
            while(busy.size() && busy.top().first<=m[0]){
                auto [_, room]=busy.top();busy.pop();
                avaliable.push(room);
            }
            int room;
            long long endtime;
            if(avaliable.size()){
                room=avaliable.top();
                avaliable.pop();
                endtime=m[1];
            }else{
                auto [time, _room]=busy.top();busy.pop();
                room=_room;
                endtime=time+m[1]-m[0];
            }
            cnt[room]++;
            busy.push({endtime,room});
        }

        int room=0;
        for(int i=1;i<n;i++) if(cnt[i]>cnt[room]) room=i;
        return room;
    }
};
