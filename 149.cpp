#include<vector>
#include<unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;

        if(n==1) return 1;

        for(int i=0;i<n;i++){
            unordered_map<double,int> slope;
            for(int j=i+1;j<n;j++){
                auto firstPoint=points[i];
                auto secondPoint=points[j];
                int x1=firstPoint[0],y1=firstPoint[1];
                int x2=secondPoint[0],y2=secondPoint[1];
                if(x1==x2) slope[INT_MAX]++;
                else slope[1.0*(y1-y2)/(x1-x2)]++;
            }
            for(auto [_, onLine]:slope) ans=max(ans,onLine+1);
        }

        return ans;
    }
};