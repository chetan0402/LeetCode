#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            auto n=points.size();
            sort(points.begin(),points.end());
            int end=points[0][1];
            int ans=1;
            for(int i=1;i<n;i++){
                if(points[i][0]>end){
                    ans++;
                    end=points[i][1];
                }else end=min(end,points[i][1]);
            }
            return ans;
        }
    };