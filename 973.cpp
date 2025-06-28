#include<vector>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double,int,int>> pq;
        
        for(auto&point:points){
            int x=point[0];
            int y=point[1];
            pq.push({sqrt(x*x+y*y),x,y});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> ans;
        while(pq.size()){
            auto [_, x, y]=pq.top();
            pq.pop();
            ans.push_back({x,y});
        }

        return ans;
    }
};