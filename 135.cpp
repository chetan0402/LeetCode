#include<vector>
#include<queue>
#include<numeric>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            auto n=ratings.size();
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
            for(int i=0;i<n;i++) pq.push({ratings[i],i});
            int ans=0;
            vector<int> candle(n,0);
            while(!pq.empty()){
                auto [rating, i] = pq.top();
                pq.pop();
                auto candle_to_set=1;
                if(i>0 && ratings[i-1]<ratings[i]) candle_to_set=candle[i-1]+1;
                if(i<n-1 && ratings[i]>ratings[i+1]) candle_to_set=max(candle_to_set,candle[i+1]+1);
                candle[i]=candle_to_set;
                ans+=candle[i];
            }
            return ans;
        }
    };

// The question came again in daily
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        auto n=ratings.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        
        for(int i=0;i<n;i++) pq.push({ratings[i],i});

        vector<int> candies(n,1);

        while(pq.size()){
            auto [_, i]=pq.top();
            pq.pop();

            if(i>0){
                if(ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]) candies[i]=candies[i-1]+1;
            }
            if(i<n-1){
                if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) candies[i]=max(candies[i],candies[i+1]+1);
            }
        }

        return accumulate(candies.begin(),candies.end(),0);
    }
};